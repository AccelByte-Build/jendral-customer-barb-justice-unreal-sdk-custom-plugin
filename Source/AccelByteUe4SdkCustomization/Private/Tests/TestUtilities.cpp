// Copyright (c) 2021 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#include "TestUtilities.h"

#include "HttpManager.h"
#include "HttpModule.h"
#include "Api/AccelByteUserApi.h"
#include "Core/AccelByteEnvironment.h"
#include "Core/AccelByteError.h"
#include "Core/AccelByteHttpRetryScheduler.h"
#include "Models/AccelByteUserModels.h"

DEFINE_LOG_CATEGORY(LogAccelByteCustomizationTest);

FString GetEnvironmentVariable(const FString Name, const int32 MaxValueLength = 100)
{
	FString Value = Environment::GetEnvironmentVariable(Name, MaxValueLength + 1);

	if (Value.Len() > MaxValueLength)
	{
		UE_LOG(LogTemp, Fatal, TEXT("Environment variable value is too long: %s"), *Name);
	}

	return FString::Printf(TEXT("%s"), *Value);
}

FString GetMandatoryEnvironmentVariable(const FString Name, const int32 MaxValueLength = 100)
{
	FString Value = GetEnvironmentVariable(Name, MaxValueLength);

	if (Value.IsEmpty())
	{
		UE_LOG(LogTemp, Fatal, TEXT("Missing mandatory environment variable: %s"), *Name);
	}

	return FString::Printf(TEXT("%s"), *Value);
}

FString GetAdminBaseUrl()
{
	return GetMandatoryEnvironmentVariable(TEXT("ADMIN_BASE_URL"));
}

FString GetPublisherNamespace()
{
	return GetMandatoryEnvironmentVariable(TEXT("PUBLISHER_NAMESPACE"));
}

FString GetAdminClientId()
{
	return GetMandatoryEnvironmentVariable(TEXT("ADMIN_CLIENT_ID"));
}

FString GetAdminClientSecret()
{
	return GetMandatoryEnvironmentVariable(TEXT("ADMIN_CLIENT_SECRET"));
}

FString GetAdminUserName()
{
	return GetMandatoryEnvironmentVariable(TEXT("ADMIN_USER_NAME"));
}

FString GetAdminUserPass()
{
	return GetMandatoryEnvironmentVariable(TEXT("ADMIN_USER_PASS"));
}

bool GetAdminUserAccessToken(FString& OutValue)
{
	static FString AdminUserTokenCache;
	static double AdminUserTokenExpiry;

	double CurrentTime = FPlatformTime::Seconds();

	if (!AdminUserTokenCache.IsEmpty() && CurrentTime < AdminUserTokenExpiry)
	{
		OutValue = AdminUserTokenCache;

		return true;
	}

	bool bIsDone = false;
	bool bIsOk  = false;

	FString Authorization = TEXT("Basic " + FBase64::Encode(FString::Printf(TEXT("%s:%s"),
		*GetAdminClientId(), *GetAdminClientSecret())));
	FString Url = FString::Printf(TEXT("%s/iam/oauth/token"),
		*GetAdminBaseUrl());
	FString Content = FString::Printf(TEXT("grant_type=password&username=%s&password=%s"),
		*FGenericPlatformHttp::UrlEncode(GetAdminUserName()), *FGenericPlatformHttp::UrlEncode(GetAdminUserPass()));

	AB_HTTP_POST_FORM(Request, Url, Authorization, Content);

	FOauth2Token TokenResult;
	CurrentTime = FPlatformTime::Seconds();

	FRegistry::HttpRetryScheduler.ProcessRequest(
		Request,
		CreateHttpResultHandler(
			THandler<FOauth2Token>::CreateLambda([&](const FOauth2Token& Result)
				{
					TokenResult = Result;
					bIsOk = true;
					bIsDone = true;
				}),
			FErrorHandler::CreateLambda([&](int32 ErrorCode, const FString& ErrorMessage)
				{
					bIsDone = true;
				})),
		CurrentTime);

	Waiting(bIsDone, "Waiting ...");

	if (!bIsOk)
	{
		return false;
	}

	OutValue = TokenResult.Access_token;
	AdminUserTokenCache = TokenResult.Access_token;
	AdminUserTokenExpiry = CurrentTime + TokenResult.Expires_in;

	return true;
}

bool RegisterTestUser(FApiClient& ApiClient, const FTestUser& InTestUser)
{
	bool bIsDone = false;
	bool bIsOk = false;

	ApiClient.User.Register(
		InTestUser.Email,
		InTestUser.Password,
		InTestUser.DisplayName,
		InTestUser.Country,
		InTestUser.DateOfBirth,
		THandler<FRegisterResponse>::CreateLambda([&](const FRegisterResponse& Result)
			{
				bIsOk = true;
				bIsDone = true;
			}),
		FErrorHandler::CreateLambda([&](int32 Code, FString Message)
			{
				if ((ErrorCodes)Code == ErrorCodes::UserEmailAlreadyUsedException)
				{
					bIsOk = true;
				}
				bIsDone = true;
			}));

	Waiting(bIsDone, TEXT("Waiting ..."));

	return bIsOk;
}

bool LoginTestUser(FApiClient& ApiClient, const FTestUser& OutTestUser)
{
	bool bIsDone = false;
	bool bIsOk = false;

	ApiClient.User.LoginWithUsername(
		OutTestUser.Email,
		OutTestUser.Password,
		FVoidHandler::CreateLambda([&]()
			{
				bIsOk = true;
				bIsDone = true;
			}),
		FErrorHandler::CreateLambda([&](int32 ErrorCode, const FString& ErrorMessage)
			{
				bIsDone = true;
			}));

	Waiting(bIsDone, TEXT("Waiting ..."));

	return bIsOk;
}

bool SetupTestUser(FApiClient& ApiClient)
{
	FTestUser TestUser;

	return SetupTestUser(ApiClient, TestUser);
}

bool SetupTestUser(FApiClient& ApiClient, FTestUser& OutTestUser)
{
	OutTestUser = FTestUser();

	if (!RegisterTestUser(ApiClient, OutTestUser))
	{
		return false;
	}

	if (!LoginTestUser(ApiClient, OutTestUser))
	{
		return false;
	}

	return true;
}

bool TearDownTestUser(FApiClient& ApiClient)
{
	bool bIsDone;
	bool bIsOk;

	FString AdminUserAccessToken;

	if (!GetAdminUserAccessToken(AdminUserAccessToken))
	{
		return false;
	}

	FString Authorization = FString::Printf(TEXT("Bearer %s"),
		*AdminUserAccessToken);
	FString Url = FString::Printf(TEXT("%s/iam/namespaces/%s/users/%s"),
		*GetAdminBaseUrl(), *FRegistry::Settings.Namespace, *ApiClient.CredentialsRef->GetUserId());

	AB_HTTP_DELETE(Request, Url, Authorization);

	bIsDone = false;
	bIsOk = false;

	FRegistry::HttpRetryScheduler.ProcessRequest(
		Request,
		CreateHttpResultHandler(
			FSimpleDelegate::CreateLambda([&]
				{
					bIsOk = true;
					bIsDone = true;
				}),
			FErrorHandler::CreateLambda([&](int32 ErrorCode, const FString& ErrorMessage)
				{
					bIsDone = true;
				})),
		FPlatformTime::Seconds());

	Waiting(bIsDone, TEXT("Waiting ..."));

	if (!bIsOk)
	{
		return false;
	}

	return bIsOk;
}

void Waiting(bool& bCondition, FString Message, double TimeoutDelay)
{
	const double StartTime = FPlatformTime::Seconds();
	const double TimeoutSeconds = StartTime + TimeoutDelay;
	double LastTickTime = StartTime;

	while (!bCondition && (FPlatformTime::Seconds() < TimeoutSeconds))
	{
		FPlatformProcess::Sleep(.2f);
		UE_LOG(LogTemp, Log, TEXT("%s"), *Message);
		LastTickTime = FPlatformTime::Seconds();
		FHttpModule::Get().GetHttpManager().Tick(.2f);
		FTicker::GetCoreTicker().Tick(.2f);
	}

	if (FPlatformTime::Seconds() >= TimeoutSeconds)
	{
		UE_LOG(LogTemp, Error, TEXT("Waiting timed out, message %s"), *Message);
	}
}

// Copyright (c) 2022 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#pragma once

#include "Core/AccelByteMultiRegistry.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAccelByteCustomizationTest, Log, All);

#define AB_TEST_TRUE(Expr) UTEST_TRUE(TEXT(#Expr), Expr)
#define AB_TEST_FALSE(Expr) UTEST_FALSE(TEXT(#Expr), Expr)
#define AB_TEST_VALID(Ptr) UTEST_VALID(TEXT(#Ptr), Ptr)
#define AB_TEST_INVALID(Ptr) UTEST_INVALID(TEXT(#Ptr), Ptr)
#define AB_TEST_NOT_NULL(Ptr) UTEST_NOT_NULL(TEXT(#Ptr), Ptr)
#define AB_TEST_NULL(Ptr) UTEST_NULL(TEXT(#Ptr), Ptr)
#define AB_TEST_EQUAL(Actual, Expected) UTEST_EQUAL(TEXT(#Actual), Actual, Expected)
#define AB_TEST_NOT_EQUAL(Actual, Expected) UTEST_NOT_EQUAL(TEXT(#Actual " and " #Expected), Actual, Expected)
#define AB_TEST_SAME(Actual, Expected) UTEST_SAME(TEXT(#Actual " and " #Expected)), Actual, Expected)
#define AB_TEST_NOT_SAME(Actual, Expected) UTEST_NOT_SAME(TEXT(#Actual " and " #Expected)), Actual, Expected)

#define AB_HTTP_REQUEST(Name, URL, Verb, Authorization, ContentType, Content) \
	FHttpRequestPtr Name = FHttpModule::Get().CreateRequest(); \
	Name->SetURL(URL); \
	Name->SetHeader(TEXT("Authorization"), Authorization); \
	Name->SetVerb(Verb); \
	Name->SetHeader(TEXT("Content-Type"), ContentType); \
	Name->SetHeader(TEXT("Accept"), TEXT("application/json")); \
	Name->SetContentAsString(Content);
#define AB_HTTP_GET(Name, URL, Authorization) \
	AB_HTTP_REQUEST(Name, URL, TEXT("GET"), Authorization,  TEXT("application/json"), TEXT(""))
#define AB_HTTP_DELETE(Name, URL, Authorization) \
	AB_HTTP_REQUEST(Name, URL, TEXT("DELETE"), Authorization, TEXT("application/json"), TEXT(""))
#define AB_HTTP_POST(Name, URL, Authorization, Content) \
	AB_HTTP_REQUEST(Name, URL, TEXT("POST"), Authorization, TEXT("application/json"), Content)
#define AB_HTTP_POST_FORM(Name, URL, Authorization, Content) \
	AB_HTTP_REQUEST(Name, URL, TEXT("POST"), Authorization, TEXT("application/x-www-form-urlencoded"), Content)
#define AB_HTTP_PUT(Name, URL, Authorization, Content) \
	AB_HTTP_REQUEST(Name, URL, TEXT("PUT"), Authorization, TEXT("application/json"), Content)
#define AB_HTTP_PATCH(Name, URL, Authorization, Content) \
	AB_HTTP_REQUEST(Name, URL, TEXT("PATCH"), Authorization, TEXT("application/json"), Content)

struct FTestUser
{
	FString FirstName = TEXT("John");
	FString LastName = TEXT("Doe");
	FString DateOfBirth = TEXT("2000-01-01");
	FString Country = TEXT("US");
	FString Language = TEXT("en");
	FString Timezone = TEXT("Etc/UTC");
	FString DisplayName;
	FString Email;
	FString Password = TEXT("Password123!");
	FString AvatarSmallUrl = TEXT("http://example.com/avatar/small.jpg");
	FString AvatarUrl = TEXT("http://example.com/avatar/normal.jpg");
	FString AvatarLargeUrl = TEXT("http://example.com/avatar/large.jpg");
	Credentials Credentials;

	FTestUser(const int32 UserIndex = 0) : FTestUser(
		FGuid::NewGuid().ToString(EGuidFormats::Digits).Left(8), UserIndex)
	{}

	FTestUser(const FString& TestUID, const int32 UserIndex = 0) :
		DisplayName(FString::Printf(TEXT("%s%s-%s-%02d"), 
			*FirstName, *LastName, *TestUID, UserIndex).ToLower()),
		Email(FString::Printf(TEXT("%s-%s-%02d@example.com"), 
			TEXT("justice-unreal-sdk"), *TestUID, UserIndex).ToLower())
	{}
};
FString GetAdminBaseUrl();
FString GetPublisherNamespace();
FString GetAdminClientId();
FString GetAdminClientSecret();
FString GetAdminUserName();
FString GetAdminUserPass();
bool GetAdminUserAccessToken(FString& OutValue);

bool SetupTestUser(FApiClient& ApiClient);
bool SetupTestUser(FApiClient& ApiClient, FTestUser& OutTestUser);
bool TearDownTestUser(FApiClient& ApiClient);

void Waiting(bool& bcondition, FString Message, double TimeoutDelay = 60.0);

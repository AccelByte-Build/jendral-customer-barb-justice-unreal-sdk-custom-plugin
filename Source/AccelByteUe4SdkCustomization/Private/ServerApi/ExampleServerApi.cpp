// Copyright (c) 2022 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#include "ServerApi/ExampleServerApi.h"

namespace AccelByte
{
	namespace Api
	{
		ExampleServerApi::ExampleServerApi(ServerCredentials const& CredentialsRef, ServerSettings const& SettingsRef, FHttpRetryScheduler& HttpRef) :
			FServerApiBase(CredentialsRef, SettingsRef, HttpRef)
		{}
		
		ExampleServerApi::~ExampleServerApi() {}
	}
}
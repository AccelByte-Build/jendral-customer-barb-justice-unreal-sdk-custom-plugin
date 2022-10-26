// Copyright (c) 2022 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#include "Api/ExampleApi.h"

namespace AccelByte
{
	namespace Api
	{
		ExampleApi::ExampleApi(Credentials const& CredentialsRef, Settings const& SettingsRef, FHttpRetryScheduler& HttpRef) :
			FApiBase(CredentialsRef, SettingsRef, HttpRef)
		{}
		
		ExampleApi::~ExampleApi() {}
	}
}
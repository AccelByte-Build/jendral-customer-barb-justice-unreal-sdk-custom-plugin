// Copyright (c) 2022 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#pragma once

#include "Core/AccelByteMultiRegistry.h"
#include "Core/AccelByteHttpRetryScheduler.h"

namespace AccelByte
{
	namespace Api
	{
		class ACCELBYTEUE4SDKCUSTOMIZATION_API ExampleApi : FApiBase
		{
		public:
			ExampleApi(Credentials const& CredentialsRef, Settings const& SettingsRef, FHttpRetryScheduler& HttpRef);
			~ExampleApi();
		};
	}
}
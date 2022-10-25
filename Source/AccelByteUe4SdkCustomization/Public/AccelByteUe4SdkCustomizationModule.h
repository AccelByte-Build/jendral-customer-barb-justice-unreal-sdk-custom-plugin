// Copyright (c) 2021 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#pragma once

#include "CoreMinimal.h"

/** Log category for any AccelByte Customization logs, including traces */
DECLARE_LOG_CATEGORY_EXTERN(LogAccelByteCustomization, Warning, All);

class IAccelByteUe4SdkCustomizationModuleInterface : public IModuleInterface
{
public:
	static IAccelByteUe4SdkCustomizationModuleInterface& Get();

	static bool IsAvailable();
};

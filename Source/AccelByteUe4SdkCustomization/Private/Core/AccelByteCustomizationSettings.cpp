// Copyright (c) 2021 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#include "Core/AccelByteCustomizationSettings.h"

using namespace AccelByte;

CustomizationSettings& CustomizationSettings::Get()
{
	static CustomizationSettings StaticCustomizationSettings;
	return StaticCustomizationSettings;
}

UAccelByteCustomizationSettings::UAccelByteCustomizationSettings()
{
}

void UAccelByteBlueprintsCustomizationSettings::SetCustomizationUrlExample(const FString& CustomizationUrlExample)
{
	CustomizationSettings::Get().CustomizationUrlExample = CustomizationUrlExample;
}

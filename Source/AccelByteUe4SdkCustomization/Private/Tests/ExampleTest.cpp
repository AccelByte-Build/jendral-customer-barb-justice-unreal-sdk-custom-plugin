// Copyright (c) 2022 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#include "AccelByteUe4SdkModule.h"
#include "Core/AccelByteCustomizationSettings.h"
#include "Core/AccelByteEnvironment.h"
#include "Misc/AutomationTest.h"
#include "TestUtilities.h"


IMPLEMENT_SIMPLE_AUTOMATION_TEST(CustomizationUpdateEnvironment, "AccelByte.Customization.CustomizationUpdateEnvironment",
								 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool CustomizationUpdateEnvironment::RunTest(const FString& Parameters)
{
	IAccelByteUe4SdkModuleInterface& ABSDKModule = IAccelByteUe4SdkModuleInterface::Get();
	ESettingsEnvironment ExpectedNewEnvironment = ESettingsEnvironment::Production;
	const FString OldUrl = AccelByte::CustomizationSettings::Get().CustomizationUrlExample;
	ABSDKModule.SetEnvironment(ExpectedNewEnvironment);
	const FString NewUrl = AccelByte::CustomizationSettings::Get().CustomizationUrlExample;
	AB_TEST_NOT_EQUAL(OldUrl, NewUrl);

	return true;
}
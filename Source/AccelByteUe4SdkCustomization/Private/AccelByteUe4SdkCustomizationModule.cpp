// Copyright (c) 2021 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#include "AccelByteUe4SdkCustomizationModule.h"
#include "Modules/ModuleManager.h"
#include "Core/AccelByteRegistry.h"
#include "Core/AccelByteCustomizationSettings.h"
#include "AccelByteUe4SdkModule.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"

DEFINE_LOG_CATEGORY(LogAccelByteCustomization);

IAccelByteUe4SdkCustomizationModuleInterface& IAccelByteUe4SdkCustomizationModuleInterface::Get()
{
	return FModuleManager::LoadModuleChecked<IAccelByteUe4SdkCustomizationModuleInterface>("AccelByteUe4SdkCustomization");
}

bool IAccelByteUe4SdkCustomizationModuleInterface::IsAvailable()
{
	return FModuleManager::Get().IsModuleLoaded("AccelByteUe4SdkCustomization");
}

class FAccelByteUe4SdkCustomizationModule : public IAccelByteUe4SdkCustomizationModuleInterface
{
    virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	// For registering settings in UE4 editor
	void RegisterSettings();
	void UnregisterSettings();

	bool LoadSettingsFromConfigUObject();
	void RefreshEnvironmentSettings(const ESettingsEnvironment Environment);

private:
	FDelegateHandle OnEnvironmentChangedHandle;
};

void FAccelByteUe4SdkCustomizationModule::StartupModule()
{
	IAccelByteUe4SdkModuleInterface* Module = static_cast<IAccelByteUe4SdkModuleInterface*>(&FModuleManager::Get().LoadModuleChecked("AccelByteUe4Sdk"));
	if(Module != nullptr)
	{
		OnEnvironmentChangedHandle = Module->OnEnvironmentChanged().AddRaw(this, &FAccelByteUe4SdkCustomizationModule::RefreshEnvironmentSettings);
	}
	RegisterSettings();
	RefreshEnvironmentSettings(ESettingsEnvironment::Default);
}

void FAccelByteUe4SdkCustomizationModule::ShutdownModule()
{
	IAccelByteUe4SdkModuleInterface& Module = IAccelByteUe4SdkModuleInterface::Get();
	Module.OnEnvironmentChanged().Remove(OnEnvironmentChangedHandle);

	UnregisterSettings();
}

void FAccelByteUe4SdkCustomizationModule::RefreshEnvironmentSettings(const ESettingsEnvironment Environment)
{
	LoadSettingsFromConfigUObject();
}

bool FAccelByteUe4SdkCustomizationModule::LoadSettingsFromConfigUObject()
{
	const FString ConfigPath = TEXT("/Script/AccelByteUe4SdkCustomization.AccelByteCustomizationSettings");
	
	FString CustomizationUrl;
	GConfig->GetString(*ConfigPath, TEXT("CustomizationUrlExample"), CustomizationUrl, GEngineIni);
	AccelByte::CustomizationSettings::Get().CustomizationUrlExample =
		FString::Printf(TEXT("%s/%s"), *AccelByte::FRegistry::Settings.BaseUrl, CustomizationUrl.IsEmpty() ? TEXT("DefaultValue") : *CustomizationUrl);

	return true;
}

void FAccelByteUe4SdkCustomizationModule::RegisterSettings()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings(TEXT("Project"), TEXT("Plugins"), TEXT("AccelByte Unreal Engine 4 Customization SDK"),
			FText::FromName(TEXT("AccelByte Unreal Engine 4 Customization SDK")),
			FText::FromName(TEXT("Setup your plugin.")),
			GetMutableDefault<UAccelByteCustomizationSettings>()
		);
		if (SettingsSection.IsValid())
		{
			SettingsSection->OnModified().BindRaw(this, &FAccelByteUe4SdkCustomizationModule::LoadSettingsFromConfigUObject);
			SettingsSection->OnSave().BindRaw(this, &FAccelByteUe4SdkCustomizationModule::LoadSettingsFromConfigUObject);
			SettingsSection->OnSaveDefaults().BindRaw(this, &FAccelByteUe4SdkCustomizationModule::LoadSettingsFromConfigUObject);
		}
	}
#endif
}

void FAccelByteUe4SdkCustomizationModule::UnregisterSettings()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings(TEXT("Project"), TEXT("Plugins"), TEXT("AccelByte Unreal Engine 4 Customization SDK"));
	}
#endif
}


IMPLEMENT_MODULE(FAccelByteUe4SdkCustomizationModule, AccelByteUe4SdkCustomization)

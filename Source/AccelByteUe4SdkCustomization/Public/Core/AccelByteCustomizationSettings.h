// Copyright (c) 2022 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AccelByteCustomizationSettings.generated.h"

namespace AccelByte
{

class ACCELBYTEUE4SDKCUSTOMIZATION_API CustomizationSettings
{
public:
	static CustomizationSettings& Get();
	FString CustomizationUrlExample;
};

} // Namespace AccelByte

/**
 * @brief UObject for storing customization settings into configuration file.
 */
UCLASS(Config = Engine, defaultConfig)
class ACCELBYTEUE4SDKCUSTOMIZATION_API UAccelByteCustomizationSettings : public UObject
{
	GENERATED_BODY()
public:
	UAccelByteCustomizationSettings();

	UPROPERTY(EditAnywhere, Config, Category = "AccelByte Customization | Settings")
	FString CustomizationUrlExample;
};


/**
 * @brief Get or update customization settings via blueprint.
 */
UCLASS(Blueprintable, BlueprintType)
class UAccelByteBlueprintsCustomizationSettings : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "AccelByte Customization | Settings")
	static void SetCustomizationUrlExample(const FString& CustomizationUrlExample);
};


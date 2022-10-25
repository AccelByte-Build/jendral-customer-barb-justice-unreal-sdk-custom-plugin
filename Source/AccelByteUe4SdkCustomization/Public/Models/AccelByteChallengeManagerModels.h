// Copyright (c) 2021 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Models/AccelByteGeneralModels.h"

#include "AccelByteChallengeManagerModels.generated.h"

UENUM(BlueprintType)
enum class EAccelByteChallengeActionDefSortBy : uint8
{
	NONE = 0,
	createdAt,
	updatedAt
};

UENUM(BlueprintType)
enum class EAccelByteChallengeDefSortBy : uint8
{
	NONE = 0,
	createdAt,
	weight, 
	startDate,
	endDate
};

UENUM(BlueprintType)
enum class EAccelByteChallengePlayerSortBy : uint8
{
	NONE = 0,
	createdAt,
	startDate,
	endDate
};


UENUM(BlueprintType)
enum class EAccelByteChallengePlayerActionsSortBy : uint8
{
	NONE = 0,
	time,
	actionType,
	userId
};

UENUM(BlueprintType)
enum class EAccelByteChallengeDefActiveStatus : uint8
{
	NONE = 0,
	ACTIVE,
	INACTIVE
};

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EAccelByteChallengeStatus : uint8
{
	// @brief None equal to All if use to querying.
	NONE = 0,
	ACTIVE,
	COMPLETED,
	DISABLED,
	EXPIRED
};
ENUM_CLASS_FLAGS(EAccelByteChallengeStatus)

UENUM(BlueprintType)
enum class EAccelByteChallengeSchedule : uint8
{
	DAILY = 0,
	WEEKLY,
	SEASONAL,
	GALLERY
};


USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsChallengeReward
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FString ItemId{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		int32 Quantity{};
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsChallengeTask
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FString ActionDefId{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		int32 ActionType{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FString Description{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		int32 Order{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FJsonObjectWrapper Payload;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		int32 TimesToRepeat{};
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsChallengeDefinition
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FString Category{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FDateTime CreatedAt{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FDateTime StartDate{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FDateTime EndDate{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		bool ForceAssign{false};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FString Id{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		bool IsActive{false};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		bool IsSequential{false};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		TArray<FAccelByteModelsChallengeReward> Rewards{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		EAccelByteChallengeSchedule Schedule{EAccelByteChallengeSchedule::DAILY};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		TArray<FAccelByteModelsChallengeTask> Tasks{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FString UpdatedAt{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		int32 Weight{};
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsDistributeRewardsResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	TArray<FString> EntitlementIds{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	FString ErrorMsg{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	FDateTime GrantedAt{0};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	FString GrantedBy{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	FString ItemId{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	int32 Quantity{0};
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsChallengeResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	FAccelByteModelsChallengeDefinition ChallengeDef{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	FDateTime CreatedAt{0};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	FDateTime EndAt{0};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	TArray<FAccelByteModelsDistributeRewardsResponse> GrandStatuses;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	FString Id{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	FDateTime StartDate{0};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	EAccelByteChallengeStatus Status{EAccelByteChallengeStatus::NONE};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	TArray<FAccelByteModelsChallengeTask> Tasks{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	FDateTime UpdatedAt{0};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	FString UserId{};
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsChallengeListResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	TArray<FAccelByteModelsChallengeResponse> Data{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	FAccelByteModelsPaging Paging{};
};

USTRUCT(BlueprintType)
struct FAccelByteModelsChallengeCreateRequestActionDefinition
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		int32 ActionType{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FString Description{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FJsonObjectWrapper Payload;
};

USTRUCT(BlueprintType)
struct FAccelByteModelsChallengeActionDefinition
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		int32 ActionType{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FString Description{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FJsonObjectWrapper Payload;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FString Id{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FDateTime CreatedAt{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FDateTime UpdatedAt{0};
};

USTRUCT(BlueprintType)
struct FAccelByteModelsChallengeActionDefResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		TArray<FAccelByteModelsChallengeActionDefinition> Data{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
		FAccelByteModelsPaging Paging{};
};

USTRUCT(BlueprintType)
struct FAccelByteModelsChallengeCreateRequestChallengeDefinition
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FString Category{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FString StartDate{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		FString EndDate{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		bool ForceAssign{false};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		bool IsActive{false};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		bool IsSequential{false};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		TArray<FAccelByteModelsChallengeReward> Rewards{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		EAccelByteChallengeSchedule Schedule{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		TArray<FAccelByteModelsChallengeTask> Tasks{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		int32 Weight{};
};

USTRUCT(BlueprintType)
struct FAccelByteModelsChallengeDefResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
		TArray<FAccelByteModelsChallengeDefinition> Data{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
		FAccelByteModelsPaging Paging{};
	
};

USTRUCT(BlueprintType)
struct FAccelByteModelsPlayerAction
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	int32 ActionType{0};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	FString Id{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	FJsonObjectWrapper Payload;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	TArray<FString> PlayerChallengeIds{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	FDateTime Time{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	FString UserId{};
};

USTRUCT(BlueprintType)
struct FAccelByteModelsPlayerActionsResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	TArray<FAccelByteModelsPlayerAction> Data{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Challenge ")
	FAccelByteModelsPaging Paging{};
};

USTRUCT(BlueprintType)
struct FPlayerChallengeStats
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	TArray<FString> Affected{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	int32 Matched{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	int32 Unaffected{0};
};

USTRUCT(BlueprintType)
struct FAccelByteModelsSubmitPlayerActionRequest
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	int32 ActionType{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	FString PaKey{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	FJsonObjectWrapper Payload;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	FString Time{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	FString UserId{};
};

USTRUCT(BlueprintType)
struct FAccelByteModelsSubmitPlayerActionResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	int32 ActionType{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	FString Id{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	FString Namespace{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	FJsonObjectWrapper Payload;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	FPlayerChallengeStats PlayerChallengeStats{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	FDateTime Time{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Challenge ")
	FString UserId{};
};

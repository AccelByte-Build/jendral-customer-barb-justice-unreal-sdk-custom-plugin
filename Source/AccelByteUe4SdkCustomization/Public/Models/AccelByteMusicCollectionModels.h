// Copyright (c) 2022 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#pragma once

#include "CoreMinimal.h"
#include "Models/AccelByteGeneralModels.h"
#include "Models/AccelByteEcommerceModels.h"
#include "AccelByteMusicCollectionModels.generated.h"

UENUM(BlueprintType)
enum class EAccelByteCollectionType : uint8
{
	NONE = 0,
	SEASON,
	FEATURED
};

UENUM(BlueprintType)
enum class EAccelByteCollectionItemType : uint8
{
	NONE = 0,
	MEDIA,
	INGAMEITEM
};

UENUM(BlueprintType)
enum class EAccelByteCollectionPublishStatus : uint8
{
	NONE = 0,
	PUBLISHED,
	UNPUBLISHED
};

UENUM(BlueprintType)
enum class EAccelByteCollectionListSortBy : uint8
{
	NONE = 0,
	START_DATE,
	CREATED_AT,
	TITLE
};

UENUM(BlueprintType)
enum class EAccelByteSongListSortBy : uint8
{
	NONE = 0,
	CREATED_AT,
	NAME,
	ARTIST,
	ALBUM
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsCollectionData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString Code{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FDateTime CreatedAt{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FDateTime EndDate{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString Id{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		EAccelByteCollectionItemType ItemType{EAccelByteCollectionItemType::NONE};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString Namespace{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FDateTime StartDate{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString Title{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		EAccelByteCollectionType Type{EAccelByteCollectionType::NONE};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FDateTime updatedAt{0};
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsGetCollectionListResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Music Collection ")
		TArray<FAccelByteModelsCollectionData> Data{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Music Collection ")
		FAccelByteModelsPaging Paging{};
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsSongBindinInfo 
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString CollectionId{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FDateTime CreatedAt{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FDateTime UpdatedAt{0};
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsSongPricing
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString CurrencyCode{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		int32 Price{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FDateTime StartDate{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FDateTime EndDate{0};
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsSongData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString Album{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString AlbumCoverLink{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString Artist{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FAccelByteModelsSongBindinInfo BindingInfo{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FDateTime CreatedAt{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString Description{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		int32 Duration{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString GameLocationId{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString Genre{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString Id{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		bool IsPublished{false};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString Isrc{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString Label{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString Name{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString PlatformItemId{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		TArray<FAccelByteModelsSongPricing> Pricing{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FDateTime ReleaseDate{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString SampleLink{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FString TunedGlobalId{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | Music Collection ")
		FDateTime UpdatedAt{0};
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsGetSongListResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Music Collection ")
		TArray<FAccelByteModelsSongData> Data{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Music Collection ")
		FAccelByteModelsPaging Paging{};
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsInGameItemImage
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		FString As{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		FString Url{};

};
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsInGameItemEntitlementType
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		EAccelByteEntitlementType Name{EAccelByteEntitlementType::NONE};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		bool Stackable{false};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		int32 UseCount{};
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsInGameItemData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		FString Id{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		FString Name{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		FString Description{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection")
		bool IsPublished{false};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		FString PlatformItemId{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		TArray<FAccelByteModelsSongPricing> Pricing{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		FDateTime CreatedAt{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		FDateTime UpdatedAt{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		FAccelByteModelsSongBindinInfo BindingInfo{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		bool PurchasableInStore{false};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		FString Sku{}; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		bool VisibleInStore{false}; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		TArray<FString> YouTubeVideos{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		TArray<FAccelByteModelsInGameItemImage> Images{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AccelByte | Category | Models | InGameItem Collection ")
		FAccelByteModelsInGameItemEntitlementType EntitlementType{};
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDKCUSTOMIZATION_API FAccelByteModelsGetInGameItemListResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | InGameItem Collection ")
		TArray<FAccelByteModelsInGameItemData> Data{};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | InGameItem Collection ")
		FAccelByteModelsPaging Paging{};
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "JsonParser/MapTileStruct.h"

#include "MapModel.generated.h"

/**
 * 
 */
UCLASS()
class SOKOBAN_API UMapModel : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<FMapTileStruct> TilesStructs;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Height;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Width;
};

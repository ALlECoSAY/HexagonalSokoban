// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SocobanParser.generated.h"

/**
 * 
 */
class UMapModel;

UCLASS()
class SOKOBAN_API USocobanParser : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	static UMapModel* ParseMap(FString FilePath);

};

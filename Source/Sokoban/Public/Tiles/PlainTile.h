// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tiles/BaseTile.h"
#include "PlainTile.generated.h"

/**
 * 
 */
UCLASS()
class SOKOBAN_API APlainTile : public ABaseTile
{
	GENERATED_BODY()

public:
	virtual bool CanPass() override;

	
};

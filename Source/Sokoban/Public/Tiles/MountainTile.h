// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tiles/BaseTile.h"
#include "MountainTile.generated.h"

/**
 * 
 */
UCLASS()
class SOKOBAN_API AMountainTile : public ABaseTile
{
	GENERATED_BODY()

public:

	virtual bool CanPass() override;

};

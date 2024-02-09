// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SokobanGameMode.generated.h"

class UMapModel;

UCLASS(minimalapi)
class ASokobanGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASokobanGameMode();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UMapModel* MapModel;
};




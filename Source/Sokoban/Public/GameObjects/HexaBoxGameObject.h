// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Enums/HexDirection.h"

#include "CoreMinimal.h"
#include "PushableGameObject.h"
#include "GameFramework/Actor.h"
#include "HexaBoxGameObject.generated.h"

class ABaseTile;

UCLASS()
class SOKOBAN_API AHexaBoxGameObject : public AActor, public IPushableGameObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHexaBoxGameObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	ABaseTile* CurrentTile;

	virtual void Push(EHexDirection PushDirection) override;
	virtual bool CanBePushed(EHexDirection PushDirection) override;

};

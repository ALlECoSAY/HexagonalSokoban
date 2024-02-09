// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Passable.h"
#include "GameFramework/Actor.h"

#include "Enums/TileType.h"
#include "Enums/ObjectType.h"

#include "BaseTile.generated.h"

class UStaticMeshComponent;
class IPushableGameObject;

UCLASS(Abstract)
class SOKOBAN_API ABaseTile : public AActor, public IPassable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseTile();
	ABaseTile(ETileType TileType, EObjectType ObjectType);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	ABaseTile* GetNeighbor(EHexDirection Direction);



	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(VisibleAnywhere)
	ETileType TileType;

	UPROPERTY(VisibleAnywhere)
	TScriptInterface<IPushableGameObject> PushableGameObject;

	//Neighbors
	UPROPERTY(VisibleAnywhere)
	ABaseTile* NW;
	UPROPERTY(VisibleAnywhere)
	ABaseTile* NE;
	UPROPERTY(VisibleAnywhere)
	ABaseTile* E;
	UPROPERTY(VisibleAnywhere)
	ABaseTile* SE;
	UPROPERTY(VisibleAnywhere)
	ABaseTile* SW;
	UPROPERTY(VisibleAnywhere)
	ABaseTile* W;

	virtual bool CanPass() override { return false; };


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Enums/TileType.h"
#include "Enums/ObjectType.h"

#include "MapManager.generated.h"

class UMapModel;
class ABaseTile;
class AMountainTile;
class APlainTile;
class AActiveTile;

UCLASS()
class SOKOBAN_API AMapManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapManager();


	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(VisibleAnywhere, Category = "MapGrid")
	UMapModel* MapModel;

	UPROPERTY(VisibleAnywhere, Category = "MapGrid")
	TArray<ABaseTile*> TileList;

	UPROPERTY(EditAnywhere, Category = "MapGrid|Tiles")
	TSubclassOf<ABaseTile> SpawnTileAsset;
	UPROPERTY(EditAnywhere, Category = "MapGrid|Tiles")
	TSubclassOf<AActiveTile> ActiveTileAsset;
	UPROPERTY(EditAnywhere, Category = "MapGrid|Tiles")
	TSubclassOf<APlainTile> PlainTileAsset;
	UPROPERTY(EditAnywhere, Category = "MapGrid|Tiles")
	TSubclassOf<AMountainTile> MountainTileAsset;
	UPROPERTY(EditAnywhere, Category = "MapGrid|GameObjects")
	TSubclassOf<AActor> PlayerAsset;
	UPROPERTY(EditAnywhere, Category = "MapGrid|GameObjects")
	TSubclassOf<AActor> BoxAsset;


	UPROPERTY(EditAnywhere, Category = "MapGrid|Layout")
	float TileHorizontalOffset = 173.2050807568877f;
	UPROPERTY(EditAnywhere, Category = "MapGrid|Layout")
	float TileOddRowHorizontalOffset = 86.60254037844386f;
	UPROPERTY(EditAnywhere, Category = "MapGrid|Layout")
	float TileVerticalOffset = 150.f;
	UPROPERTY(EditAnywhere, Category = "MapGrid|Layout")
	float TileGapDistance = 5.f;

protected:
	ABaseTile* SpawnNewTile(ETileType TileType, FVector Location);
	AActor* SpawnNewGameObject(EObjectType GameObjectType, ABaseTile* Tile);
	void ResizeTileGrid(int32 x, int32 y);
	void SetupTileConnections();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<TArray<ABaseTile*>> TileGrid;



};

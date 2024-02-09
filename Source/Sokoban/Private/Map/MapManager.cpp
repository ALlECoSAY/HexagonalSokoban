// Fill out your copyright notice in the Description page of Project Settings.


#include "Map/MapManager.h"

#include "JsonParser/MapModel.h"
#include "JsonParser/SocobanParser.h"
#include "Tiles/BaseTile.h"
#include "Tiles/ActiveTile.h"
#include "Tiles/PlainTile.h"
#include "Tiles/MountainTile.h"

// Sets default values
AMapManager::AMapManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ABaseTile* AMapManager::SpawnNewTile(ETileType TileType, FVector Location)
{
	TSubclassOf<ABaseTile> TileToSpawn;
	FActorSpawnParameters Params; 
	switch (TileType) {
	case ETileType::NONE:
		break;
	case ETileType::ACTIVE_PLAIN:
		TileToSpawn = ActiveTileAsset;
		break;
	case ETileType::DEFAULT_PLAIN:
		TileToSpawn = PlainTileAsset;
		break;
	case ETileType::SPAWN_PLAIN:
		TileToSpawn = SpawnTileAsset;
		break;
	case ETileType::MOUNTAIN:
		TileToSpawn = MountainTileAsset;
		break;
	}
	ABaseTile* CreatedTile = GetWorld()->SpawnActor<ABaseTile>(TileToSpawn, Location, FRotator::ZeroRotator, Params);
	return CreatedTile;
}

AActor* AMapManager::SpawnNewGameObject(EObjectType GameObjectType, ABaseTile* Tile)
{
	TSubclassOf<AActor> GameObjectToSpawn;
	FActorSpawnParameters Params;

	switch (GameObjectType) {
	case EObjectType::NONE: 
		return nullptr;
		break;
	case EObjectType::Player:
		GameObjectToSpawn = PlayerAsset;
		break;
	case EObjectType::Box: 
		GameObjectToSpawn = BoxAsset;
		break;
	}

	const FVector TileLoc = Tile->GetActorLocation();
	const FVector SpawnLoc = FVector(TileLoc.X, TileLoc.Y, TileLoc.Z + 100);
	return GetWorld()->SpawnActor<AActor>(GameObjectToSpawn, SpawnLoc, FRotator::ZeroRotator, Params);

}


void AMapManager::ResizeTileGrid(int32 x, int32 y)
{
	TileGrid.SetNumZeroed(x);
	for(int32 i = 0; i< TileGrid.Num(); ++i)
	{
		TileGrid[i].SetNumZeroed(y);
	}
}


void AMapManager::SetupTileConnections()
{
	const int32 xMax = MapModel->Width;
	const int32 yMax = MapModel->Height;
	for(int32 x = 0; x < xMax; ++x)
	{
		for(int32 y = 0; y < yMax; ++y)
		{
			ABaseTile* CurrentTile = TileGrid[x][y];
			const bool bIsOddRow = y % 2 == 1;
			
			//E neighbor connection
			if(TileGrid.IsValidIndex(x+1))
			{
				CurrentTile->E = TileGrid[x + 1][y];
			}
			//W neighbor connection
			if (TileGrid.IsValidIndex(x - 1))
			{
				CurrentTile->W = TileGrid[x - 1][y];
			}
			if(bIsOddRow)
			{
				//SE neighbor connection
				if (TileGrid.IsValidIndex(x + 1) && TileGrid[x + 1].IsValidIndex(y + 1))
				{
					CurrentTile->SE = TileGrid[x + 1][y + 1];
				}
				//SW neighbor connection
				if (TileGrid.IsValidIndex(x) && TileGrid[x].IsValidIndex(y + 1))
				{
					CurrentTile->SW = TileGrid[x][y + 1];
				}
				//NW neighbor connection
				if (TileGrid.IsValidIndex(x) && TileGrid[x].IsValidIndex(y - 1))
				{
					CurrentTile->NW = TileGrid[x][y - 1];
				}
				//NE neighbor connection
				if (TileGrid.IsValidIndex(x + 1) && TileGrid[x + 1].IsValidIndex(y - 1))
				{
					CurrentTile->NE = TileGrid[x + 1][y - 1];
				}
			} else
			{
				//SE neighbor connection
				if (TileGrid.IsValidIndex(x) && TileGrid[x].IsValidIndex(y + 1))
				{
					CurrentTile->SE = TileGrid[x][y + 1];
				}
				//SW neighbor connection
				if (TileGrid.IsValidIndex(x - 1) && TileGrid[x - 1].IsValidIndex(y + 1))
				{
					CurrentTile->SW = TileGrid[x - 1][y + 1];
				}
				//NW neighbor connection
				if (TileGrid.IsValidIndex(x - 1) && TileGrid[x - 1].IsValidIndex(y - 1))
				{
					CurrentTile->NW = TileGrid[x - 1][y - 1];
				}
				//NE neighbor connection
				if (TileGrid.IsValidIndex(x) && TileGrid[x].IsValidIndex(y - 1))
				{
					CurrentTile->NE = TileGrid[x][y - 1];
				}
			}
		}
	}
}

// Called when the game starts or when spawned
void AMapManager::BeginPlay()
{
	Super::BeginPlay();

	MapModel = USocobanParser::ParseMap("map1.json");

	TileHorizontalOffset += TileGapDistance;
	TileVerticalOffset += TileGapDistance;
	TileOddRowHorizontalOffset += TileGapDistance / 2;


	FVector ZeroLocation = GetActorLocation();
	const float zPos = ZeroLocation.Z;
	const int32 Height = MapModel->Height;
	const int32 Width = MapModel->Width;
	ResizeTileGrid(Width, Height);
	for (int32 y = 0; y < Height; ++y)
	{
		for (int32 x = 0; x < Width; ++x)
		{
			const bool bIsOddRow = y % 2 == 1;
			const float xPos = bIsOddRow ? x * TileHorizontalOffset + TileOddRowHorizontalOffset : x * TileHorizontalOffset;
			const float yPos = y * TileVerticalOffset;

			FMapTileStruct Current = MapModel->TilesStructs[y * Width + x];
			
			ABaseTile* Tile = SpawnNewTile(Current.Tile,FVector{xPos, yPos, zPos});
			SpawnNewGameObject(Current.Object, Tile);

			TileList.Add(Tile);
			TileGrid[x][y] = Tile;

		}
	}
	SetupTileConnections();
}

// Called every frame
void AMapManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


#pragma once

#include "CoreMinimal.h"

#include "Enums/TileType.h"
#include "Enums/ObjectType.h"

#include "MapTileStruct.generated.h"

USTRUCT(BlueprintType)
struct FMapTileStruct
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
	ETileType Tile = ETileType::NONE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
	EObjectType Object = EObjectType::NONE;

};
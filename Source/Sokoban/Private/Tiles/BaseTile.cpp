// Fill out your copyright notice in the Description page of Project Settings.


#include "Tiles/BaseTile.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Enums/HexDirection.h"

// Sets default values
ABaseTile::ABaseTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	auto* Root = CreateDefaultSubobject<USceneComponent>("RootCmp");
	SetRootComponent(Root);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	StaticMeshComponent->SetupAttachment(RootComponent);


}

ABaseTile::ABaseTile(ETileType TileType, EObjectType ObjectType)
{
	PrimaryActorTick.bCanEverTick = true;

	this->TileType = TileType;
}

// Called when the game starts or when spawned
void ABaseTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ABaseTile* ABaseTile::GetNeighbor(EHexDirection Direction)
{
	switch (Direction)
	{
	case EHexDirection::NORTH_WEST:
		return NW;
	case EHexDirection::NORTH_EAST:
		return NE;
	case EHexDirection::EAST:
		return E;
	case EHexDirection::SOUTH_EAST:
		return SE;
	case EHexDirection::SOUTH_WEST:
		return SW;
	case EHexDirection::WEST:
		return W;
	default:
		return nullptr;
	}
}

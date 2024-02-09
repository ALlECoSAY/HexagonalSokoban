// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObjects/HexaBoxGameObject.h"

#include "Tiles/BaseTile.h"


// Sets default values
AHexaBoxGameObject::AHexaBoxGameObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHexaBoxGameObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHexaBoxGameObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHexaBoxGameObject::Push(EHexDirection PushDirection)
{
	auto* Neighbor = CurrentTile->GetNeighbor(PushDirection);
	if (Neighbor)
	{
		CurrentTile->PushableGameObject = nullptr;
		Neighbor->PushableGameObject = this;
	}
}

bool AHexaBoxGameObject::CanBePushed(EHexDirection PushDirection)
{
	auto* Neighbor = CurrentTile->GetNeighbor(PushDirection);
	if(Neighbor)
	{
		return Neighbor->CanPass();
	}
	return false;
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "SokobanGameMode.h"
#include "SokobanPlayerController.h"
#include "SokobanCharacter.h"
#include "JsonParser/SocobanParser.h"
#include "JsonParser/MapModel.h"
#include "UObject/ConstructorHelpers.h"

ASokobanGameMode::ASokobanGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ASokobanPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	//if (PlayerPawnBPClass.Class != nullptr)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
	DefaultPawnClass = nullptr;

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}



	

}

void ASokobanGameMode::BeginPlay()
{
	Super::BeginPlay();

	//MapModel = USocobanParser::ParseMap("map1.json");
}

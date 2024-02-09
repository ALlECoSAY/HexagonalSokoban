// Copyright Epic Games, Inc. All Rights Reserved.

#include "SokobanCharacter.h"

#include "Tiles/BaseTile.h"



#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputTriggers.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"

ASokobanCharacter::ASokobanCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	//CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ASokobanCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void ASokobanCharacter::BeginPlay()
{
	Super::BeginPlay();

	
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			if (!InputMapping.IsNull())
			{
				Subsystem->AddMappingContext(InputMapping.LoadSynchronous(), 0);
			}
		}
	}

	//todo enhance repossess method
	GetWorld()->GetFirstPlayerController()->Possess(this);
	
}

void ASokobanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(IA_Move_NW, ETriggerEvent::Started, this, &ThisClass::TryMove, EHexDirection::NORTH_WEST);
		EnhancedInputComponent->BindAction(IA_Move_NE, ETriggerEvent::Started, this, &ThisClass::TryMove, EHexDirection::NORTH_EAST);
		EnhancedInputComponent->BindAction(IA_Move_E, ETriggerEvent::Started, this, &ThisClass::TryMove, EHexDirection::EAST);
		EnhancedInputComponent->BindAction(IA_Move_SE, ETriggerEvent::Started, this, &ThisClass::TryMove, EHexDirection::SOUTH_EAST);
		EnhancedInputComponent->BindAction(IA_Move_SW, ETriggerEvent::Started, this, &ThisClass::TryMove, EHexDirection::SOUTH_WEST);
		EnhancedInputComponent->BindAction(IA_Move_W, ETriggerEvent::Started, this, &ThisClass::TryMove, EHexDirection::WEST);
	}

}

void ASokobanCharacter::TryMove(EHexDirection Dir)
{
	switch (Dir)
	{
	case EHexDirection::NORTH_WEST:


		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, TEXT("NORTH_WEST PRESSED"));
		break;
	case EHexDirection::NORTH_EAST:


		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, TEXT("NORTH_EAST PRESSED"));
		break;
	case EHexDirection::EAST:


		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, TEXT("EAST PRESSED"));
		break;
	case EHexDirection::SOUTH_EAST:


		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, TEXT("SOUTH_EAST PRESSED"));
		break;
	case EHexDirection::SOUTH_WEST:


		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, TEXT("SOUTH_WEST PRESSED"));
		break;
	case EHexDirection::WEST:


		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, TEXT("WEST PRESSED"));
		break;
	default: 
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, TEXT("default PRESSED"));
	}
}

void ASokobanCharacter::Move(EHexDirection Dir)
{
	//move to next tile


	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, TEXT("D3 PRESSED"));
}

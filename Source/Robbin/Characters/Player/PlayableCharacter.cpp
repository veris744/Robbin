// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayableCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "C:/Program Files/Epic Games/UE_5.3/Engine/Plugins/Experimental/Animation/ContextualAnimation/Source/ContextualAnimationEditor/Public/ContextualAnimEdMode.h"
#include "RobbinPlayerController.h"
#include "Robbin/InteractiveActors/InteractiveActor.h"

APlayableCharacter::APlayableCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
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

void APlayableCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APlayableCharacter::ExecuteAbility(AbilityOn Ability)
{
	switch (Ability)
	{
	case AbilityOn::ABILITY1:
		DoAbility1();
		break;
	case AbilityOn::ABILITY2:
		DoAbility2();
		break;
	case AbilityOn::ABILITY3:
		DoAbility3();
		break;
	case AbilityOn::ABILITY4:
		DoAbility4();
		break;
	case AbilityOn::ABILITY5:
		DoAbility5();
		break;
	case AbilityOn::ABILITY6:
		DoAbility6();
		break;
	case AbilityOn::ABILITY7:
		DoAbility7();
		break;
	default:
		break;
	}
}

// Called to bind functionality to input
void APlayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayableCharacter::AddMovementInput(FVector WorldDirection, float ScaleValue, bool bForce)
{
	FHitResult Hit;
	bool bHitSuccessful = false;
	bHitSuccessful = Cast<ARobbinPlayerController>(GetController())->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);

	if (bHitSuccessful)
	{
		if (!Hit.GetActor()->GetClass()->IsChildOf(AInteractiveActor::StaticClass()))
		{
			ARobbinPlayerController* RobbingController = Cast<ARobbinPlayerController>(Controller);

			if (Controller && RobbingController->ActiveAbility == AbilityOn::NOTACTIVE)
			{
				Super::AddMovementInput(WorldDirection, ScaleValue, bForce);
			}
		}
	}

}


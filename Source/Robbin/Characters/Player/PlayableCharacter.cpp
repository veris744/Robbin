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


	//Setup Abilities
	UAbility* OpenCloseDoors = NewObject<UAbility>();
	OpenCloseDoors->DisplayName = "Open/Close Door";
	OpenCloseDoors->Description = "Open/Close Door";
	OpenCloseDoors->AbilityNo = AbilityNumber::ABILITY1;
	OpenCloseDoors->ID = "TECH1";
	OpenCloseDoors->bNeedInteractuable = true;
	Abilities.Add(OpenCloseDoors);

	UAbility* DestroyDoors = NewObject<UAbility>();
	DestroyDoors->DisplayName = "Destroy Door";
	DestroyDoors->Description = "Destroy Door";
	DestroyDoors->AbilityNo = AbilityNumber::ABILITY2;
	DestroyDoors->ID = "TECH2";
	Abilities.Add(DestroyDoors);

	UAbility* UAbility3 = NewObject<UAbility>();
	UAbility3->DisplayName = "UAbility 3";
	UAbility3->Description = "UAbility 3";
	UAbility3->AbilityNo = AbilityNumber::ABILITY3;
	UAbility3->ID = "TECH3";
	Abilities.Add(UAbility3);

	
}

void APlayableCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APlayableCharacter::ExecuteUAbility(UAbility* ability)
{
	switch (ability->AbilityNo)
	{
	case AbilityNumber::ABILITY1:
		DoAbility1();
		break;
	case AbilityNumber::ABILITY2:
		DoAbility2();
		break;
	case AbilityNumber::ABILITY3:
		DoAbility3();
		break;
	case AbilityNumber::ABILITY4:
		DoAbility4();
		break;
	case AbilityNumber::ABILITY5:
		DoAbility5();
		break;
	case AbilityNumber::ABILITY6:
		DoAbility6();
		break;
	case AbilityNumber::ABILITY7:
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

			if (Controller && RobbingController->ActiveAbility == nullptr)
			{
				Super::AddMovementInput(WorldDirection, ScaleValue, bForce);
			}
		}
	}

}


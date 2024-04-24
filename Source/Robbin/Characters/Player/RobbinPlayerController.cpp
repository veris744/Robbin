// Copyright Epic Games, Inc. All Rights Reserved.

#include "RobbinPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "Robbin/RobbinCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Robbin/InteractiveActors/InteractiveActor.h"
#include "PlayableCharacter.h"
#include <Robbin/Abilities/StaticAbilities.h>

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

ARobbinPlayerController::ARobbinPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;

	bEnableMouseOverEvents = true;
}

void ARobbinPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void ARobbinPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Setup mouse input events
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Started, this, &ARobbinPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnSetDestinationTriggered);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Completed, this, &ARobbinPlayerController::OnSetDestinationReleased);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Canceled, this, &ARobbinPlayerController::OnSetDestinationReleased);

		// Setup touch input events
		//EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Started, this, &ARobbinPlayerController::OnInputStarted);
		//EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnTouchTriggered);
		//EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Completed, this, &ARobbinPlayerController::OnTouchReleased);
		//EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Canceled, this, &ARobbinPlayerController::OnTouchReleased);
	
		EnhancedInputComponent->BindAction(StartUAbility1Action, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnUseUAbility1);
		EnhancedInputComponent->BindAction(StartUAbility2Action, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnUseUAbility2);
		EnhancedInputComponent->BindAction(StartUAbility3Action, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnUseUAbility3);
		EnhancedInputComponent->BindAction(StartUAbility4Action, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnUseUAbility4);
		EnhancedInputComponent->BindAction(StartUAbility5Action, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnUseUAbility5);
		EnhancedInputComponent->BindAction(StartUAbility6Action, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnUseUAbility6);
		EnhancedInputComponent->BindAction(StartUAbility7Action, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnUseUAbility7);

	
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ARobbinPlayerController::OnInputStarted()
{
	StopMovement();
}

// Triggered every frame when the input is held down
void ARobbinPlayerController::OnSetDestinationTriggered()
{
	// We flag that the input is being pressed
	FollowTime += GetWorld()->GetDeltaSeconds();
	
	// We look for the location in the world where the player has pressed the input
	FHitResult Hit;
	bool bHitSuccessful = false;
	if (bIsTouch)
	{
		bHitSuccessful = GetHitResultUnderFinger(ETouchIndex::Touch1, ECollisionChannel::ECC_Visibility, true, Hit);
	}
	else
	{
		bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);
	}

	// If we hit a surface, cache the location
	if (bHitSuccessful)
	{
		if (Hit.GetActor()->GetClass()->IsChildOf(AInteractiveActor::StaticClass()))
		{
			DestinationActor = Hit.GetActor();
		}
		else
		{
			DestinationActor = nullptr;
			CachedDestination = Hit.Location;
		}
	}
	
	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void ARobbinPlayerController::OnSetDestinationReleased()
{
	//No Active UAbility and Click On Floor
	if (!DestinationActor && ActiveAbility == nullptr)
	{
		// If it was a short press
		if (FollowTime <= ShortPressThreshold)
		{
			// We move there and spawn some particles
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
		}

		FollowTime = 0.f;
	}
	else
	{
		AInteractiveActor* Interactive = nullptr;
		if (DestinationActor)
		{
			Interactive = Cast<AInteractiveActor>(DestinationActor);
		}

		Cast<APlayableCharacter>(GetCharacter())->ExecuteAbility(ActiveAbility, Interactive);

		DestinationActor = nullptr;
		ActiveAbility = nullptr;
	}


	//Active UAbility and Click On Floor
	//else if (!DestinationActor && ActiveAbility != nullptr)
	//{
	//	if (ActiveAbility->bNeedInteractuable)
	//	{
	//		ActiveAbility = nullptr;
	//		return;
	//	}
	//	else
	//	{
	//		ActiveAbility = nullptr;
	//		return;
	//	}
	//}

	////No Active UAbility and Click On Object
	//else if (DestinationActor && ActiveAbility == nullptr)
	//{
	//	AInteractiveActor* Interactive = Cast<AInteractiveActor>(DestinationActor);

	//	Interactive->Activate(nullptr);
	//}

	////Active UAbility and Click On Object
	//else
	//{
	//	AInteractiveActor* Interactive = Cast<AInteractiveActor>(DestinationActor);

	//	if (Interactive->Abilities.IsEmpty())
	//	{
	//		ActiveAbility = nullptr;
	//		return;
	//	}

	//	for (FString AbilityId : Interactive->Abilities)
	//	{
	//		if (AbilityId == ActiveAbility->ID)
	//		{
	//			Interactive->Activate(ActiveAbility);
	//			DestinationActor = nullptr;
	//			ActiveAbility = nullptr;
	//			return;
	//		}
	//	}		
	//}
}

void ARobbinPlayerController::OnUseUAbility1()
{
	APlayableCharacter* GamePlayer = Cast<APlayableCharacter>(GetCharacter());
	FString AbilityId = FindAbilityId(GamePlayer->Type, 1);
	ActiveAbility = UStaticAbilities::GetFromId(AbilityId);
}

void ARobbinPlayerController::OnUseUAbility2()
{
	APlayableCharacter* GamePlayer = Cast<APlayableCharacter>(GetCharacter());
	FString AbilityId = FindAbilityId(GamePlayer->Type, 2);
	ActiveAbility = UStaticAbilities::GetFromId(AbilityId);
}

void ARobbinPlayerController::OnUseUAbility3()
{
	APlayableCharacter* GamePlayer = Cast<APlayableCharacter>(GetCharacter());
	FString AbilityId = FindAbilityId(GamePlayer->Type, 3);
	ActiveAbility = UStaticAbilities::GetFromId(AbilityId);
}

void ARobbinPlayerController::OnUseUAbility4()
{
	APlayableCharacter* GamePlayer = Cast<APlayableCharacter>(GetCharacter());
	FString AbilityId = FindAbilityId(GamePlayer->Type, 4);
	ActiveAbility = UStaticAbilities::GetFromId(AbilityId);
}

void ARobbinPlayerController::OnUseUAbility5()
{
	APlayableCharacter* GamePlayer = Cast<APlayableCharacter>(GetCharacter());
	FString AbilityId = FindAbilityId(GamePlayer->Type, 5);
	ActiveAbility = UStaticAbilities::GetFromId(AbilityId);
}

void ARobbinPlayerController::OnUseUAbility6()
{
	APlayableCharacter* GamePlayer = Cast<APlayableCharacter>(GetCharacter());
	FString AbilityId = FindAbilityId(GamePlayer->Type, 6);
	ActiveAbility = UStaticAbilities::GetFromId(AbilityId);
}

void ARobbinPlayerController::OnUseUAbility7()
{
	APlayableCharacter* GamePlayer = Cast<APlayableCharacter>(GetCharacter());
	FString AbilityId = FindAbilityId(GamePlayer->Type, 7);
	ActiveAbility = UStaticAbilities::GetFromId(AbilityId);
}

FString ARobbinPlayerController::FindAbilityId(CharacterType Type, int num)
{
	FString AbilityID = "";

	switch (Type)
	{
	case CharacterType::TECH:
		AbilityID += "TECH";
		break;
	case CharacterType::SPY:
		AbilityID += "SPY";
		break;
	case CharacterType::SCAMMER:
		AbilityID += "SCAM";
		break;
	default:
		break;
	}

	AbilityID += FString::FromInt(num);

	return AbilityID;
}


// Triggered every frame when the input is held down
//void ARobbinPlayerController::OnTouchTriggered()
//{
//	bIsTouch = true;
//	OnSetDestinationTriggered();
//}
//
//void ARobbinPlayerController::OnTouchReleased()
//{
//	bIsTouch = false;
//	OnSetDestinationReleased();
//}


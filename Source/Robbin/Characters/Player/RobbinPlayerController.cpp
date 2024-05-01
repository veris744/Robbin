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
#include <Robbin/UI/MainUserWidget.h>
#include "TechCharacter.h"
#include "SpyCharacter.h"
#include "ScammerCharacter.h"
#include <Kismet/GameplayStatics.h>
#include "GameFramework/GameModeBase.h"
#include <Subsystems/PanelExtensionSubsystem.h>
#include <Robbin/RobbinGameMode.h>

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

ARobbinPlayerController::ARobbinPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;

	bEnableMouseOverEvents = true;

	CurrentType = CharacterType::SPY;

}

void ARobbinPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	AbilitiesManager = Cast<ARobbinGameMode>(GetWorld()->GetAuthGameMode())->GetAbilitiesManager();

	if (GetWorld())
	{
		HUDWidget = CreateWidget<UMainUserWidget>(this, HUDClass);

		if (HUDWidget)
		{
			HUDWidget->AddToViewport();
			HUDWidget->SetVisibility(ESlateVisibility::Visible);
			HUDWidget->PlayerController = this;
			HUDWidget->setCharacterColor(CurrentType);
		}
	}

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayableCharacter::StaticClass(), actors);

	for (AActor* a : actors)
	{
		APlayableCharacter* pc = Cast<APlayableCharacter>(a);
		switch (pc->Type)
		{
		case CharacterType::TECH:
			TechCharacter = pc;
			break;
		case CharacterType::SPY:
			SpyCharacter = pc;
			break;
		case CharacterType::SCAMMER:
			ScamCharacter = pc;
			break;
		default:
			break;
		}
	}

	if (CurrentType == CharacterType::TECH)
		Possess(TechCharacter);
	else if (CurrentType == CharacterType::SPY)
		Possess(SpyCharacter);
	else if (CurrentType == CharacterType::SCAMMER)
		Possess(ScamCharacter);
}

APlayableCharacter* ARobbinPlayerController::GetCurrentCharacter()
{
	if (CurrentType == CharacterType::TECH)
		return TechCharacter;
	else if (CurrentType == CharacterType::SPY)
		return SpyCharacter;
	else if (CurrentType == CharacterType::SCAMMER)
		return ScamCharacter;

	return nullptr;
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
		
		EnhancedInputComponent->BindAction(RotateRAction, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnSetRotateRTriggered);
		EnhancedInputComponent->BindAction(RotateLAction, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnSetRotateLTriggered);
		EnhancedInputComponent->BindAction(ZoomInAction, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnSetZoomInTriggered);
		EnhancedInputComponent->BindAction(ZoomOutAction, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnSetZoomOutTriggered);

		EnhancedInputComponent->BindAction(StartAbility1Action, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnUseUAbility1);
		EnhancedInputComponent->BindAction(StartAbility2Action, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnUseUAbility2);
		EnhancedInputComponent->BindAction(StartAbility3Action, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnUseUAbility3);
		EnhancedInputComponent->BindAction(StartAbility4Action, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnUseUAbility4);
		EnhancedInputComponent->BindAction(StartAbility5Action, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnUseUAbility5);
		EnhancedInputComponent->BindAction(StartAbility6Action, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnUseUAbility6);
		EnhancedInputComponent->BindAction(StartAbility7Action, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnUseUAbility7);


		EnhancedInputComponent->BindAction(SetCharacterTech, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnChangeCharacterTech);
		EnhancedInputComponent->BindAction(SetCharacterSpy, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnChangeCharacterSpy);
		EnhancedInputComponent->BindAction(SetCharacterScam, ETriggerEvent::Triggered, this, &ARobbinPlayerController::OnChangeCharacterScam);

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

		HUDWidget->SetAbilityButtonColor(0);
	}
}

void ARobbinPlayerController::OnSetRotateRTriggered()
{
	if (HUDWidget->bInGameMode)
		GetCurrentCharacter()->RotateCamera(true);
}

void ARobbinPlayerController::OnSetRotateLTriggered()
{
	if (HUDWidget->bInGameMode)
		GetCurrentCharacter()->RotateCamera(false);
}

void ARobbinPlayerController::OnSetZoomInTriggered()
{
	if (HUDWidget->bInGameMode)
		GetCurrentCharacter()->ZoomCamera(true);
}

void ARobbinPlayerController::OnSetZoomOutTriggered()
{
	if (HUDWidget->bInGameMode)
		GetCurrentCharacter()->ZoomCamera(false);
}


void ARobbinPlayerController::OnUseUAbility1()
{
	APlayableCharacter* GamePlayer = Cast<APlayableCharacter>(GetCharacter());
	FString AbilityId = FindAbilityId(GamePlayer->Type, 1);

	if (!ActiveAbility || ActiveAbility->ID != AbilityId)
	{
		ActiveAbility = AbilitiesManager->GetFromId(AbilityId);
		HUDWidget->SetAbilityButtonColor(1);
	}
	else
	{
		ActiveAbility = nullptr;
		HUDWidget->SetAbilityButtonColor(0);
	}
}

void ARobbinPlayerController::OnUseUAbility2()
{
	APlayableCharacter* GamePlayer = Cast<APlayableCharacter>(GetCharacter());
	FString AbilityId = FindAbilityId(GamePlayer->Type, 2);

	if (!ActiveAbility || ActiveAbility->ID != AbilityId)
	{
		ActiveAbility = AbilitiesManager->GetFromId(AbilityId);
		HUDWidget->SetAbilityButtonColor(2);
	}
	else
	{
		ActiveAbility = nullptr;
		HUDWidget->SetAbilityButtonColor(0);
	}
}

void ARobbinPlayerController::OnUseUAbility3()
{
	APlayableCharacter* GamePlayer = Cast<APlayableCharacter>(GetCharacter());
	FString AbilityId = FindAbilityId(GamePlayer->Type, 3);

	if (!ActiveAbility || ActiveAbility->ID != AbilityId)
	{
		ActiveAbility = AbilitiesManager->GetFromId(AbilityId);
		HUDWidget->SetAbilityButtonColor(3);
	}
	else
	{
		ActiveAbility = nullptr;
		HUDWidget->SetAbilityButtonColor(0);
	}
}

void ARobbinPlayerController::OnUseUAbility4()
{
	APlayableCharacter* GamePlayer = Cast<APlayableCharacter>(GetCharacter());
	FString AbilityId = FindAbilityId(GamePlayer->Type, 4);

	if (!ActiveAbility || ActiveAbility->ID != AbilityId)
	{
		ActiveAbility = AbilitiesManager->GetFromId(AbilityId);
		HUDWidget->SetAbilityButtonColor(4);
	}
	else
	{
		ActiveAbility = nullptr;
		HUDWidget->SetAbilityButtonColor(0);
	}
}

void ARobbinPlayerController::OnUseUAbility5()
{
	APlayableCharacter* GamePlayer = Cast<APlayableCharacter>(GetCharacter());
	FString AbilityId = FindAbilityId(GamePlayer->Type, 5);

	if (!ActiveAbility || ActiveAbility->ID != AbilityId)
	{
		ActiveAbility = AbilitiesManager->GetFromId(AbilityId);
		HUDWidget->SetAbilityButtonColor(5);
	}
	else
	{
		ActiveAbility = nullptr;
		HUDWidget->SetAbilityButtonColor(0);
	}
}

void ARobbinPlayerController::OnUseUAbility6()
{
	APlayableCharacter* GamePlayer = Cast<APlayableCharacter>(GetCharacter());
	FString AbilityId = FindAbilityId(GamePlayer->Type, 6);

	if (!ActiveAbility || ActiveAbility->ID != AbilityId)
	{
		ActiveAbility = AbilitiesManager->GetFromId(AbilityId);
		HUDWidget->SetAbilityButtonColor(6);
	}
	else
	{
		ActiveAbility = nullptr;
		HUDWidget->SetAbilityButtonColor(0);
	}
}

void ARobbinPlayerController::OnUseUAbility7()
{
	APlayableCharacter* GamePlayer = Cast<APlayableCharacter>(GetCharacter());
	FString AbilityId = FindAbilityId(GamePlayer->Type, 7);

	if (!ActiveAbility || ActiveAbility->ID != AbilityId)
	{
		ActiveAbility = AbilitiesManager->GetFromId(AbilityId);
		HUDWidget->SetAbilityButtonColor(7);
	}
	else
	{
		ActiveAbility = nullptr;
		HUDWidget->SetAbilityButtonColor(0);
	}
}


void ARobbinPlayerController::OnChangeCharacterTech()
{
	if (GetCharacter() != TechCharacter)
	{
		StopMovement();
		Possess(TechCharacter);
		CurrentType = CharacterType::TECH;
		HUDWidget->setCharacterColor(CurrentType);
	}
}

void ARobbinPlayerController::OnChangeCharacterSpy()
{
	if (GetCharacter() != SpyCharacter)
	{
		StopMovement();
		Possess(SpyCharacter);
		CurrentType = CharacterType::SPY;
		HUDWidget->setCharacterColor(CurrentType);
	}
}

void ARobbinPlayerController::OnChangeCharacterScam()
{
	if (GetCharacter() != ScamCharacter)
	{
		StopMovement();
		Possess(ScamCharacter);
		CurrentType = CharacterType::SCAMMER;
		HUDWidget->setCharacterColor(CurrentType);
	}
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




// Copyright Epic Games, Inc. All Rights Reserved.

#include "RobbinGameMode.h"
#include "Characters/Player/RobbinPlayerController.h"
#include "RobbinCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Abilities/StaticAbilities.h"

ARobbinGameMode::ARobbinGameMode()
{
	UStaticAbilities::clear();
	UStaticAbilities::init();

	// use our custom PlayerController class
	PlayerControllerClass = ARobbinPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Characters/Player/BP_Tech"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Blueprints/Characters/Player/BP_PlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}
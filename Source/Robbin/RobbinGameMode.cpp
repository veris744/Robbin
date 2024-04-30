// Copyright Epic Games, Inc. All Rights Reserved.

#include "RobbinGameMode.h"
#include "Characters/Player/RobbinPlayerController.h"
#include "RobbinCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Abilities/StaticAbilities.h"
#include "UI/MainUserWidget.h"


ARobbinGameMode::ARobbinGameMode()
{

	AbilitiesManager = NewObject<UStaticAbilities>();
	AbilitiesManager->init();

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

	/*static ConstructorHelpers::FClassFinder<UMainUserWidget> UserWidgetBPClass(TEXT("/Game/Blueprints/UI/BP_MainUserWidget"));
	if (UserWidgetBPClass.Class != NULL)
	{
		HUDClass = UserWidgetBPClass.Class;
	}*/
}
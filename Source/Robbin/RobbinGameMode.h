// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RobbinGameMode.generated.h"


class UStaticAbilities;
class UDialoguesManager;

UCLASS(minimalapi)
class ARobbinGameMode : public AGameModeBase
{
	GENERATED_BODY()

	UStaticAbilities* AbilitiesManager;

	UDialoguesManager* DialoguesManager;

public:
	ARobbinGameMode();

	FORCEINLINE UStaticAbilities* GetAbilitiesManager() { return AbilitiesManager; };

	FORCEINLINE UDialoguesManager* GetDialoguesManager() { return DialoguesManager; };

};




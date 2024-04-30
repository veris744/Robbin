// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RobbinGameMode.generated.h"


class UStaticAbilities;

UCLASS(minimalapi)
class ARobbinGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARobbinGameMode();

	UStaticAbilities* AbilitiesManager;

	FORCEINLINE UStaticAbilities* GetAbilitiesManager() { return AbilitiesManager; };

};




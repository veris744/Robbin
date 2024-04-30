// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StaticAbilities.generated.h"

class UAbility;

/**
 * 
 */
UCLASS()
class ROBBIN_API UStaticAbilities : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
	TMap<FString, UAbility*> AllAbilities;

public:

	FORCEINLINE void clear() { AllAbilities.Empty(); };

	void init();
	UAbility* GetFromId(FString id);
	TArray<FString> GetIdsFromCharacterType(int Type);
};

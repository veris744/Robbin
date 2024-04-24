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

		static TMap<FString, UAbility*> AllAbilities;
public:

	FORCEINLINE static void clear() { AllAbilities.Empty(); };

	static void init();
	static UAbility* GetFromId(FString id);
	static TArray<FString> GetIdsFromCharacterType(int Type);
};

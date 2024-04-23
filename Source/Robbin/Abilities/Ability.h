// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.generated.h"

UENUM()
enum class AbilityNumber
{
	ABILITY1,
	ABILITY2,
	ABILITY3,
	ABILITY4,
	ABILITY5,
	ABILITY6,
	ABILITY7,
	NONE,
};


/**
 * 
 */
UCLASS()
class ROBBIN_API UAbility : public UObject
{
	GENERATED_BODY()

public:
	UAbility();
	~UAbility();

	FString ID = "";

	FString DisplayName = "";

	FString Description = "";

	AbilityNumber AbilityNo = AbilityNumber::NONE;

	bool bNeedInteractuable = false;
};

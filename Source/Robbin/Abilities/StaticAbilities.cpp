// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticAbilities.h"
#include "Ability.h"
#include <Robbin/Characters/Player/PlayableCharacter.h>


TMap<FString, UAbility*> UStaticAbilities::AllAbilities;

void UStaticAbilities::init()
{
	UAbility* Ability = NewObject<UAbility>();
	Ability->DisplayName = "Open/Close Door";
	Ability->Description = "Open/Close Door";
	Ability->AbilityNo = AbilityNumber::ABILITY1;
	Ability->ID = "TECH1";
	Ability->bNeedInteractuable = true;
	AllAbilities.Add(Ability->ID, Ability);


	UAbility* Ability2 = NewObject<UAbility>();
	Ability2->DisplayName = "Destroy Door";
	Ability2->Description = "Destroy Door";
	Ability2->AbilityNo = AbilityNumber::ABILITY2;
	Ability2->ID = "TECH2";
	AllAbilities.Add(Ability2->ID, Ability2);


	UAbility* Ability3 = NewObject<UAbility>();
	Ability3->DisplayName = "UAbility 3";
	Ability3->Description = "UAbility 3";
	Ability3->AbilityNo = AbilityNumber::ABILITY3;
	Ability3->ID = "TECH3";
	AllAbilities.Add(Ability3->ID, Ability3);


	UAbility* Ability4 = NewObject<UAbility>();
	Ability4->DisplayName = "UAbility 3";
	Ability4->Description = "UAbility 3";
	Ability4->AbilityNo = AbilityNumber::ABILITY4;
	Ability4->ID = "TECH4";
	AllAbilities.Add(Ability4->ID, Ability4);


	UAbility* Ability5 = NewObject<UAbility>();
	Ability5->DisplayName = "Destroy Door";
	Ability5->Description = "Destroy Door";
	Ability5->AbilityNo = AbilityNumber::ABILITY5;
	Ability5->ID = "TECH5";
	AllAbilities.Add(Ability5->ID, Ability5);


	UAbility* Ability6 = NewObject<UAbility>();
	Ability6->DisplayName = "Open/Close Door";
	Ability6->Description = "Open/Close Door";
	Ability6->AbilityNo = AbilityNumber::ABILITY6;
	Ability6->ID = "TECH6";
	Ability6->bNeedInteractuable = true;
	AllAbilities.Add(Ability6->ID, Ability6);


	UAbility* Ability7 = NewObject<UAbility>();
	Ability7->DisplayName = "UAbility 3";
	Ability7->Description = "UAbility 3";
	Ability7->AbilityNo = AbilityNumber::ABILITY7;
	Ability7->ID = "TECH7";
	AllAbilities.Add(Ability7->ID, Ability7);
}

UAbility* UStaticAbilities::GetFromId(FString id)
{
	for (auto pair : AllAbilities)
	{
		auto k = pair.Key;
		auto v = pair.Value;
		if (k == id)
		{
			return v;
		}
	}
	return nullptr;
}

TArray<FString> UStaticAbilities::GetIdsFromCharacterType(int Type)
{
	FString stringType = GetStringFromCharacterType(Type);
	TArray<FString> ids;

	for (auto pair : AllAbilities)
	{
		if (pair.Key.StartsWith(stringType))
		{
			ids.Add(pair.Key);
		}
	}
	return ids;
}

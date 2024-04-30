// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticAbilities.h"
#include "Ability.h"
#include <Robbin/Characters/Player/PlayableCharacter.h>


void UStaticAbilities::init()
{
	///////////////////////////////////////////////////////////////////////////////
	//TECH ////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
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
	Ability->bNeedInteractuable = true;
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
	AllAbilities.Add(Ability6->ID, Ability6);


	UAbility* Ability7 = NewObject<UAbility>();
	Ability7->DisplayName = "UAbility 3";
	Ability7->Description = "UAbility 3";
	Ability7->AbilityNo = AbilityNumber::ABILITY7;
	Ability7->ID = "TECH7";
	AllAbilities.Add(Ability7->ID, Ability7);

	///////////////////////////////////////////////////////////////////////////////
	//SPY /////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	UAbility* SpyAbility = NewObject<UAbility>();
	SpyAbility->DisplayName = "Open/Close Door";
	SpyAbility->Description = "Open/Close Door";
	SpyAbility->AbilityNo = AbilityNumber::ABILITY1;
	SpyAbility->ID = "SPY1";
	SpyAbility->bNeedInteractuable = true;
	AllAbilities.Add(SpyAbility->ID, SpyAbility);


	UAbility* SpyAbility2 = NewObject<UAbility>();
	SpyAbility2->DisplayName = "Destroy Door";
	SpyAbility2->Description = "Destroy Door";
	SpyAbility2->AbilityNo = AbilityNumber::ABILITY2;
	SpyAbility2->ID = "SPY2";
	AllAbilities.Add(SpyAbility2->ID, SpyAbility2);


	UAbility* SpyAbility3 = NewObject<UAbility>();
	SpyAbility3->DisplayName = "UAbility 3";
	SpyAbility3->Description = "UAbility 3";
	SpyAbility3->AbilityNo = AbilityNumber::ABILITY3;
	SpyAbility3->ID = "SPY3";
	AllAbilities.Add(SpyAbility3->ID, SpyAbility3);


	UAbility* SpyAbility4 = NewObject<UAbility>();
	SpyAbility4->DisplayName = "UAbility 3";
	SpyAbility4->Description = "UAbility 3";
	SpyAbility4->AbilityNo = AbilityNumber::ABILITY4;
	SpyAbility4->ID = "SPY4";
	AllAbilities.Add(SpyAbility4->ID, SpyAbility4);


	UAbility* SpyAbility5 = NewObject<UAbility>();
	SpyAbility5->DisplayName = "Destroy Door";
	SpyAbility5->Description = "Destroy Door";
	SpyAbility5->AbilityNo = AbilityNumber::ABILITY5;
	SpyAbility5->ID = "SPY5";
	AllAbilities.Add(SpyAbility5->ID, SpyAbility5);


	UAbility* SpyAbility6 = NewObject<UAbility>();
	SpyAbility6->DisplayName = "Open/Close Door";
	SpyAbility6->Description = "Open/Close Door";
	SpyAbility6->AbilityNo = AbilityNumber::ABILITY6;
	SpyAbility6->ID = "SPY6";
	AllAbilities.Add(SpyAbility6->ID, SpyAbility6);


	UAbility* SpyAbility7 = NewObject<UAbility>();
	SpyAbility7->DisplayName = "UAbility 3";
	SpyAbility7->Description = "UAbility 3";
	SpyAbility7->AbilityNo = AbilityNumber::ABILITY7;
	SpyAbility7->ID = "SPY7";
	AllAbilities.Add(SpyAbility7->ID, SpyAbility7);


	///////////////////////////////////////////////////////////////////////////////
	//SCAMMER /////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	UAbility* ScamAbility = NewObject<UAbility>();
	ScamAbility->DisplayName = "Open/Close Door";
	ScamAbility->Description = "Open/Close Door";
	ScamAbility->AbilityNo = AbilityNumber::ABILITY1;
	ScamAbility->ID = "SCAM1";
	ScamAbility->bNeedInteractuable = true;
	AllAbilities.Add(ScamAbility->ID, ScamAbility);


	UAbility* ScamAbility2 = NewObject<UAbility>();
	ScamAbility2->DisplayName = "Destroy Door";
	ScamAbility2->Description = "Destroy Door";
	ScamAbility2->AbilityNo = AbilityNumber::ABILITY2;
	ScamAbility2->ID = "SCAM2";
	AllAbilities.Add(ScamAbility2->ID, ScamAbility2);


	UAbility* ScamAbility3 = NewObject<UAbility>();
	ScamAbility3->DisplayName = "UAbility 3";
	ScamAbility3->Description = "UAbility 3";
	ScamAbility3->AbilityNo = AbilityNumber::ABILITY3;
	ScamAbility3->ID = "SCAM3";
	AllAbilities.Add(ScamAbility3->ID, ScamAbility3);


	UAbility* ScamAbility4 = NewObject<UAbility>();
	ScamAbility4->DisplayName = "UAbility 3";
	ScamAbility4->Description = "UAbility 3";
	ScamAbility4->AbilityNo = AbilityNumber::ABILITY4;
	ScamAbility4->ID = "SCAM4";
	AllAbilities.Add(ScamAbility4->ID, ScamAbility4);


	UAbility* ScamAbility5 = NewObject<UAbility>();
	ScamAbility5->DisplayName = "Destroy Door";
	ScamAbility5->Description = "Destroy Door";
	ScamAbility5->AbilityNo = AbilityNumber::ABILITY5;
	ScamAbility5->ID = "SCAM5";
	AllAbilities.Add(ScamAbility5->ID, ScamAbility5);


	UAbility* ScamAbility6 = NewObject<UAbility>();
	ScamAbility6->DisplayName = "Open/Close Door";
	ScamAbility6->Description = "Open/Close Door";
	ScamAbility6->AbilityNo = AbilityNumber::ABILITY6;
	ScamAbility6->ID = "SCAM6";
	AllAbilities.Add(ScamAbility6->ID, ScamAbility6);


	UAbility* ScamAbility7 = NewObject<UAbility>();
	ScamAbility7->DisplayName = "UAbility 3";
	ScamAbility7->Description = "UAbility 3";
	ScamAbility7->AbilityNo = AbilityNumber::ABILITY7;
	ScamAbility7->ID = "SCAM7";
	AllAbilities.Add(ScamAbility7->ID, ScamAbility7);

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

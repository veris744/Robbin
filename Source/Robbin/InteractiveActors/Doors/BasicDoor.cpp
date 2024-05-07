// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicDoor.h"

ABasicDoor::ABasicDoor()
{
	DisplayName = "Basic Door";

	auto Action1 = [this]()
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("thing1"));
	};

	//UAbility* action = NewObject<UAbility>();
	//action->DisplayName = FString("Testing");
	//action->Description = FString("Testing door opener");
	//action->AbilityNo = AbilityNumber::NONE;
	//action->bNeedInteractuable = true;

	auto Action2 = [this]()
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("thing2"));
	};

	//UAbility* action2 = NewObject<UAbility>();
	//action2->DisplayName = FString("Testing2");
	//action2->Description = FString("Testing door opener2");
	//action2->AbilityNo = AbilityNumber::NONE;
	//action2->bNeedInteractuable = true;

	Actions.Add(FString("NONE"), nullptr);

	DisplayableActions.Add(FString("Testing"), Action1);
	DisplayableActions.Add(FString("Testing2"), Action2);
}

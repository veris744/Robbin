// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorOpener.h"
#include "TechDoor.h"

ADoorOpener::ADoorOpener()
{
	auto OpenCloseLambda = [this]()
	{
		OpenCloseDoors();
	};

	auto DestroyDoorsLambda = [this]()
	{
		bIsUsable = false;
	};

	//UAbility* action = NewObject<UAbility>();
	//action->DisplayName = "Testing";
	//action->Description = "Testing door opener";
	//action->AbilityNo = AbilityNumber::NONE;
	//action->bNeedInteractuable = true;

	auto ActionWithoutUAbility = [this]()
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("ActionWithoutUAbility"));
	};

	Actions.Add(FString("TECH1"), OpenCloseLambda);
	Actions.Add(FString("TECH2"), DestroyDoorsLambda);
	Actions.Add(FString("NONE"), nullptr);

	DisplayableActions.Add(FString("Testing"), ActionWithoutUAbility);
}


void ADoorOpener::OpenCloseDoors()
{
	for (ATechDoor* door : DoorsToOpen)
	{
		if (door && door->bIsOpen)
			door->Close();
		else if (door)
			door->Open();
	}
}


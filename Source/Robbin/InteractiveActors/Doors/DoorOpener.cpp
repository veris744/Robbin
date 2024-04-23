// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorOpener.h"
#include "TechDoor.h"

ADoorOpener::ADoorOpener()
{
	Abilities.Add("Tech1");
	Abilities.Add("Tech2");
}

bool ADoorOpener::Activate(UAbility* ability)
{
	if (!Super::Activate(ability))	return false;

	if (DoorsToOpen.IsEmpty())	return false;

	if (ability == nullptr)
	{
		ActionWithoutUAbility();
	}

	else if (ability != nullptr && ability->ID == Abilities[0])
	{
		OpenCloseDoors();
	}

	else if (ability != nullptr && ability->ID == Abilities[1])
	{
		DestroyDoors();
	}

	return true;
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

void ADoorOpener::DestroyDoors()
{
	bIsUsable = false;
}

void ADoorOpener::ActionWithoutUAbility()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("ActionWithoutUAbility"));
}

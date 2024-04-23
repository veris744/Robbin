// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorOpener.h"
#include "TechDoor.h"

bool ADoorOpener::Activate()
{
	if (!Super::Activate())	return false;

	if (DoorsToOpen.IsEmpty())	return false;

	for (ATechDoor* door : DoorsToOpen)
	{
		if (door && door->bIsOpen)
			door->Close();
		else if (door)
			door->Open();
	}

	return true;
}

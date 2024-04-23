// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorOpener.h"
#include "TechDoor.h"

void ADoorOpener::Activate()
{
	if (DoorsToOpen.IsEmpty())	return;

	for (ATechDoor* door : DoorsToOpen)
	{
		if (door && door->bIsOpen)
			door->Close();
		else if (door)
			door->Open();
	}
}

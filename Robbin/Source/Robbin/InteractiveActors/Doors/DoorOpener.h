// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Robbin/InteractiveActors/InteractiveActor.h"
#include "DoorOpener.generated.h"

class ATechDoor;

/**
 * 
 */
UCLASS()
class ROBBIN_API ADoorOpener : public AInteractiveActor
{
	GENERATED_BODY()
	
public:

	virtual void Activate() override;

	UPROPERTY(EditAnywhere, Category = "Robbing")
		TArray<ATechDoor*> DoorsToOpen;
};
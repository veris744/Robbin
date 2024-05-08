// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Robbin/InteractiveActors/InteractiveActor.h"
#include "SuspiciousBag.generated.h"

/**
 * 
 */
UCLASS()
class ROBBIN_API ASuspiciousBag : public AInteractiveActor
{
	GENERATED_BODY()
	
public:

	ASuspiciousBag();

	void GrabBag();

	AScammerCharacter* Character;
};

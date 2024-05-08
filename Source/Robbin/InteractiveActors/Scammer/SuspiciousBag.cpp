// Fill out your copyright notice in the Description page of Project Settings.


#include "SuspiciousBag.h"
#include "Robbin/Characters/Player/ScammerCharacter.h"

ASuspiciousBag::ASuspiciousBag()
{
	DisplayName = "Bag";

	auto GrabLambda = [this]()
	{
		GrabBag();
	};

	Actions.Add(FString("NONE"), nullptr);

	DisplayableActions.Add(FString("Remove Bag"), GrabLambda);

}

void ASuspiciousBag::GrabBag()
{
	Character->SuspiciousBag = nullptr;
	Destroy();
}

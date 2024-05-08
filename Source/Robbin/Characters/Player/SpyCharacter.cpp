// Fill out your copyright notice in the Description page of Project Settings.


#include "SpyCharacter.h"
#include <Kismet/GameplayStatics.h>
#include <Robbin/Characters/AI/NPCs/GenericNPC.h>

void ASpyCharacter::DoAbility1()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGenericNPC::StaticClass(), FoundActors);

	for (AActor* a : FoundActors)
	{
		AGenericNPC* npc = Cast<AGenericNPC>(a);
		npc->ShowVisionCone(!bIsVisionActivated);
	}
	bIsVisionActivated = !bIsVisionActivated;
}

void ASpyCharacter::DoAbility2()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Spy Ability2"));
}

void ASpyCharacter::DoAbility3()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Spy Ability3"));
}

void ASpyCharacter::DoAbility4()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Spy Ability4"));
}

void ASpyCharacter::DoAbility5()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Spy Ability5"));
}

void ASpyCharacter::DoAbility6()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Spy Ability6"));
}

void ASpyCharacter::DoAbility7()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Spy Ability7"));
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "ScammerCharacter.h"
#include <Robbin/InteractiveActors/Scammer/SuspiciousBag.h>

void AScammerCharacter::DoAbility1()
{
	if (!SuspiciousBag)
	{
		FHitResult Hit;
		bool bActorIsHit = GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECC_Camera, false, Hit);

		if (bActorIsHit && !Hit.GetActor()->GetClass()->IsChildOf(APlayableCharacter::StaticClass())
			&& !Hit.GetActor()->GetClass()->IsChildOf(AInteractiveActor::StaticClass()))
		{
			FVector Location = Hit.Location;

			if (FVector::DistSquared(Location, GetActorLocation()) <= LeaveBagRange * LeaveBagRange)
			{
				FActorSpawnParameters SpawnInfo;
				SuspiciousBag = GetWorld()->SpawnActor<ASuspiciousBag>(BagClass,
					Location, FRotator(), SpawnInfo);

				SuspiciousBag->Character = this;
			}
		}
	}
	else
	{
		//do npc shit
	}
	
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Scammer Ability1"));
}

void AScammerCharacter::DoAbility2()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Scammer Ability2"));
}

void AScammerCharacter::DoAbility3()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Scammer Ability3"));
}

void AScammerCharacter::DoAbility4()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Scammer Ability4"));
}

void AScammerCharacter::DoAbility5()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Scammer Ability5"));
}

void AScammerCharacter::DoAbility6()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Scammer Ability6"));
}

void AScammerCharacter::DoAbility7()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Scammer Ability7"));
}

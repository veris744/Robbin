// Fill out your copyright notice in the Description page of Project Settings.


#include "GenericCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AGenericCharacter::AGenericCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

}

// Called when the game starts or when spawned
void AGenericCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGenericCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


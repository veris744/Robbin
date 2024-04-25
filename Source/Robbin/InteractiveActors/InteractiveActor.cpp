// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveActor.h"
#include "Components/StaticMeshComponent.h"
#include <Kismet/GameplayStatics.h>
#include "GameFramework/Character.h"

// Sets default values
AInteractiveActor::AInteractiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->OnBeginCursorOver.AddDynamic(this, &AInteractiveActor::OnBeginMouseOver);
	MeshComponent->OnEndCursorOver.AddDynamic(this, &AInteractiveActor::OnEndMouseOver);

}

// Called when the game starts or when spawned
void AInteractiveActor::BeginPlay()
{
	Super::BeginPlay();
}

void AInteractiveActor::OnBeginMouseOver(UPrimitiveComponent* TouchedComponent)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("Mouse Begin"));
}

void AInteractiveActor::OnEndMouseOver(UPrimitiveComponent* TouchedComponent)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("Mouse End"));
}

void AInteractiveActor::Hovering()
{

}

bool AInteractiveActor::Activate(UAbility* ability)
{
	if (!bIsUsable)	return false;

	
	if (bIsRanged)
	{
		float distToPlayerSQ = FVector::DistSquared(GetActorLocation(),
			UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation());

		if (distToPlayerSQ > Range * Range)
			return false;
	}

	if (!ability)
	{
		if (Actions.Contains(FString("NONE")))
			Actions[FString(FString("NONE"))]();
	}
	else if (Actions.Contains(ability->ID))
	{
		Actions[ability->ID]();
	}

	return true;
}

// Called every frame
void AInteractiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


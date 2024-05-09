// Fill out your copyright notice in the Description page of Project Settings.


#include "GenericNPC.h"
#include "NPCsAIController.h"

AGenericNPC::AGenericNPC()
{
	VisionMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Vision Mesh"));
	VisionMeshComponent->SetupAttachment(RootComponent);
}

void AGenericNPC::BeginPlay()
{
	Super::BeginPlay();

	ShowVisionCone(false);
	VisionMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	VisionMeshComponent->Mobility = EComponentMobility::Movable;
	ANPCsAIController* AIController = Cast<ANPCsAIController>(GetController());
	if (AIController)
	{
		float ancho = tan(AIController->PeripheralVisionAngleDegrees / 2) * AIController->SightRadius;
		VisionMeshComponent->SetWorldScale3D(FVector(0.001f, ancho * 2 / 100, AIController->SightRadius / 100));
		VisionMeshComponent->SetRelativeLocation(VisionMeshComponent->GetRelativeLocation() + 
			GetActorForwardVector() * (AIController->SightRadius / 4 * 3));
	}
}

UBehaviorTree* AGenericNPC::GetBehaviourTree() const
{
	return EnemyBehaviorTree;
}

APatrolPath* AGenericNPC::GetPatrolPath() const
{
	return PatrolPath;
}

void AGenericNPC::ShowVisionCone(bool bShow)
{
	if (bShow)
	{
		VisionMeshComponent->SetVisibility(true);
	}
	else
	{
		VisionMeshComponent->SetVisibility(false);
	}
}

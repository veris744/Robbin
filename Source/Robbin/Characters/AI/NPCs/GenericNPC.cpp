// Fill out your copyright notice in the Description page of Project Settings.


#include "GenericNPC.h"
#include "NPCsAIController.h"
#include "Robbin/Dialogues/DialoguesManager.h"
#include <Robbin/RobbinGameMode.h>
#include "Components/CapsuleComponent.h"


AGenericNPC::AGenericNPC()
{
	VisionMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Vision Mesh"));
	VisionMeshComponent->SetupAttachment(RootComponent);

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_EngineTraceChannel1, ECR_Block);
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
		VisionMeshComponent->SetWorldScale3D(FVector(0.001f, ancho / 100, AIController->SightRadius / 100));
		//VisionMeshComponent->SetRelativeLocation(VisionMeshComponent->GetRelativeLocation() + 
		//	GetActorForwardVector() * (AIController->SightRadius / 4 * 3));
	}

	DialoguesManager = Cast<ARobbinGameMode>(GetWorld()->GetAuthGameMode())->GetDialoguesManager();
	Dialogues = DialoguesManager->GetIdsFromNPCType(AGenericNPC::StaticClass());
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

void AGenericNPC::DialoguesTriggered()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Scammer Ability1"));

}

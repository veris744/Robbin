// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCsAIController.h"
#include "GenericNPC.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

ANPCsAIController::ANPCsAIController(FObjectInitializer const& ObjectInitializer)
{
	//AIPathFollowingComponent = CreateDefaultSubobject<UPathFollowingComponent>(TEXT("PathFollowing"));
}

void ANPCsAIController::BeginPlay()
{
	Super::BeginPlay();

	//AActor* TargetActor = GetWorld()->GetFirstPlayerController()->GetPawn();
	//if (TargetActor)
	//{
	//	MoveToActor(TargetActor);
	//}

	//AIPathFollowingComponent->SetMovComp();

	//GenericNPC = Cast<AGenericNPC>(GetCharacter());

	//if (GenericNPC == nullptr)	return;

	//EnemyBehaviorTree = GenericNPC->EnemyBehaviorTree;

	//if (EnemyBehaviorTree == nullptr)
	//{
	//	UE_LOG(LogTemp, Error, TEXT("BeginPlay : missing Behaviour Tree"));
	//	return;
	//}

	//BlackboardData = EnemyBehaviorTree->BlackboardAsset;

	//if (BlackboardData == nullptr)
	//{
	//	UE_LOG(LogTemp, Error, TEXT("BeginPlay : missing BlackboardData"));
	//	return;
	//}

	//UseBlackboard(BlackboardData, BlackboardComponent);

	//if (BlackboardComponent == nullptr)
	//{
	//	UE_LOG(LogTemp, Error, TEXT("BeginPlay : missing BlackboardComponent"));
	//	return;
	//}

	//RunBehaviorTree(EnemyBehaviorTree);
}

void ANPCsAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (AGenericNPC* const npc = Cast<AGenericNPC>(InPawn))
	{
		if (UBehaviorTree* const tree = npc->GetBehaviourTree())
		{
			UBlackboardComponent* blackboardComponent;
			UseBlackboard(tree->BlackboardAsset, blackboardComponent);
			Blackboard = blackboardComponent;
			RunBehaviorTree(tree);
		}
	}
}

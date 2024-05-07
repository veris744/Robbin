// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCsAIController.h"
#include "GenericNPC.h"
#include "Robbin/Characters/Player/PlayableCharacter.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ANPCsAIController::ANPCsAIController(FObjectInitializer const& ObjectInitializer)
{
	//AIPathFollowingComponent = CreateDefaultSubobject<UPathFollowingComponent>(TEXT("PathFollowing"));

	SetUpPerceptionSystem();
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

void ANPCsAIController::SetUpPerceptionSystem()
{
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PercepConfig"));

	if (SightConfig && PerceptionComp)
	{
		SetPerceptionComponent(*PerceptionComp);
		SightConfig->SightRadius = 500.f;
		SightConfig->LoseSightRadius = SightConfig->SightRadius + 25.f;
		SightConfig->PeripheralVisionAngleDegrees = 90.f;
		SightConfig->SetMaxAge(5.f);
		SightConfig->AutoSuccessRangeFromLastSeenLocation = 520.f;
		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

		GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
		GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ANPCsAIController::OnTargetDetected);
		GetPerceptionComponent()->ConfigureSense(*SightConfig);
	}
}

void ANPCsAIController::OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus)
{
	if (auto* const character = Cast<APlayableCharacter>(Actor))
	{
		GetBlackboardComponent()->SetValueAsBool("CanSeePlayer", Stimulus.WasSuccessfullySensed());
	}
}

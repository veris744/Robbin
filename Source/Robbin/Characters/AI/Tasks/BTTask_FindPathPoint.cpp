// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindPathPoint.h"
#include "Robbin/Characters/AI/NPCs/NPCsAIController.h"
#include "Robbin/Characters/AI/NPCs/GenericNPC.h"
#include "Robbin/Characters/AI/NPCs/PatrolPath.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FindPathPoint::UBTTask_FindPathPoint(FObjectInitializer const& ObjectInitializer) :
	UBTTask_BlackboardBase{ ObjectInitializer }
{
	NodeName = TEXT("Find Path Point");
}

EBTNodeResult::Type UBTTask_FindPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{
	if (auto* const npcController = Cast<ANPCsAIController>(OwnerComponent.GetAIOwner()))
	{
		if (auto* const BlackboardComp = OwnerComponent.GetBlackboardComponent())
		{
			auto const Index = BlackboardComp->GetValueAsInt((GetSelectedBlackboardKey()));

			if (auto* npc = Cast<AGenericNPC>(npcController->GetPawn()))
			{
				auto const Point = npc->GetPatrolPath()->GetPatrolPoint(Index);

				auto const GlobalPoint = npc->GetPatrolPath()->GetActorTransform().TransformPosition(Point);
				BlackboardComp->SetValueAsVector(PatrolPathVectorKey.SelectedKeyName, GlobalPoint);

				FinishLatentTask(OwnerComponent, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}

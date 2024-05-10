// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_IncrementPathIndex.h"
#include "Robbin/Characters/AI/NPCs/NPCsAIController.h"
#include "Robbin/Characters/AI/NPCs/GenericNPC.h"
#include "Robbin/Characters/AI/NPCs/PatrolPath.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_IncrementPathIndex::UBTTask_IncrementPathIndex(FObjectInitializer const& ObjectInitializer) :
	UBTTask_BlackboardBase{ ObjectInitializer }
{
	NodeName = TEXT("Increment Path Point");
}

EBTNodeResult::Type UBTTask_IncrementPathIndex::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{
	if (auto* const npcController = Cast<ANPCsAIController>(OwnerComponent.GetAIOwner()))
	{
		if (auto* const npc = Cast<AGenericNPC>(npcController->GetPawn()))
		{
			if (auto* const blackboardComp = OwnerComponent.GetBlackboardComponent())
			{
				auto const NoOfPoints = npc->GetPatrolPath()->Num();
				auto const MinIndex = 0;
				auto const MaxIndex = NoOfPoints - 1;
				auto Index = blackboardComp->GetValueAsInt(GetSelectedBlackboardKey());

				if (bBiDirectional)
				{
					if (Index >= MaxIndex && Direction == EDirectionType::Forward)
					{
						Direction = EDirectionType::Reverse;
					}
					else if (Index == MinIndex && Direction == EDirectionType::Reverse)
					{
						Direction = EDirectionType::Forward;
					}
				}

				blackboardComp->SetValueAsInt(GetSelectedBlackboardKey(), (Direction == EDirectionType::Forward ? ++Index : --Index) % NoOfPoints);

				FinishLatentTask(OwnerComponent, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}

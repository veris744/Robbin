// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SetBool.h"
#include "Robbin/Characters/AI/NPCs/NPCsAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTask_SetBool::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ANPCsAIController* ControllerEnemies = Cast<ANPCsAIController>(OwnerComp.GetOwner());

	UBlackboardComponent* BlackboardComponent = ControllerEnemies->GetBrainComponent()->GetBlackboardComponent();

	if (!ControllerEnemies || !BlackboardComponent) return EBTNodeResult::Aborted;

	BlackboardComponent->SetValueAsBool(Key.SelectedKeyName, BoolValue);

	return EBTNodeResult::Succeeded;
}

FString UBTTask_SetBool::GetStaticDescription() const
{
	return TEXT("Set a bool type key on the blackboard");
}
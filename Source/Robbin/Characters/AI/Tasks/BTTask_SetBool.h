// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_SetBool.generated.h"

/**
 * 
 */
UCLASS()
class ROBBIN_API UBTTask_SetBool : public UBTTaskNode
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual FString GetStaticDescription() const override;

	UPROPERTY(EditAnywhere, Category = "Input")
		bool BoolValue;

	UPROPERTY(EditAnywhere, Category = "Input")
		FBlackboardKeySelector Key;
	
};

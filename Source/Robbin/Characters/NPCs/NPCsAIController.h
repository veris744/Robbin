// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPCsAIController.generated.h"

class AGenericNPC;
/**
 * 
 */
UCLASS()
class ROBBIN_API ANPCsAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere)
		AGenericNPC* GenericNPC;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Robbin | AI")
		UBlackboardData* BlackboardData;

	UPROPERTY(VisibleAnywhere, Category = "Robbin | AI")
		UBlackboardComponent* BlackboardComponent;

	UPROPERTY(VisibleAnywhere, Category = "Robbin | AI")
		UBehaviorTree* EnemyBehaviorTree;

	/*UPROPERTY(VisibleAnywhere, Category = "Robbin | AI")
		UPathFollowingComponent* AIPathFollowingComponent;*/

public:
	explicit ANPCsAIController(FObjectInitializer const& ObjectInitializer);

	virtual void BeginPlay() override;

protected:
	virtual void OnPossess(APawn* InPawn) override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "NPCsAIController.generated.h"

class AGenericNPC;
class APlayableCharacter;/*
class ARobbinCharacter;*/
class UAIPerceptionComponent;
class UAISenseConfig_Sight;
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

	UPROPERTY(VisibleAnywhere)
		APlayableCharacter* PlayableCharacter;

	//UPROPERTY(VisibleAnywhere)
	//	ARobbinCharacter* PlayableCharacter;

		UPROPERTY()
		UAISenseConfig_Sight* SightConfig;

		UPROPERTY()
		UAIPerceptionComponent* PerceptionComp;

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

private:
	void SetUpPerceptionSystem();

	UFUNCTION()
	void OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus);
};

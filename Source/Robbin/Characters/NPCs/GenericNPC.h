// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Robbin/Characters/GenericCharacter.h"
//#include "BehaviourTree/BehaviourTree.h"
#include "GenericNPC.generated.h"

class UBehaviorTree;
class UBlackboardComponent;
/**
 * 
 */
UCLASS()
class ROBBIN_API AGenericNPC : public AGenericCharacter
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Robbin | General")
		UBehaviorTree* EnemyBehaviorTree;
		
	UPROPERTY()
		UBlackboardComponent* pMyBlackboardComponent;

		UBehaviorTree* GetBehaviourTree() const;
};

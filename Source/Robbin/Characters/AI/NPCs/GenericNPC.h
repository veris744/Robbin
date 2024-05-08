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
	AGenericNPC();

	virtual void BeginPlay() override;

	//virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, Category = "Robbing|Vision")
		UStaticMeshComponent* VisionMeshComponent;


	UPROPERTY(EditDefaultsOnly, Category = "Robbin | General")
		UBehaviorTree* EnemyBehaviorTree;
		
	UPROPERTY()
	UBlackboardComponent* pMyBlackboardComponent;

	UBehaviorTree* GetBehaviourTree() const;

	void ShowVisionCone(bool bShow);
};

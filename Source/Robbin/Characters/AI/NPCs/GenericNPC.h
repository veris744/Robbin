// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Robbin/Characters/GenericCharacter.h"
//#include "BehaviourTree/BehaviourTree.h"
#include "GenericNPC.generated.h"

class UBehaviorTree;
class UBlackboardComponent;
class APatrolPath;
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

	UBehaviorTree* GetBehaviourTree() const;

	APatrolPath* GetPatrolPath() const;

	void ShowVisionCone(bool bShow);

	UPROPERTY(VisibleAnywhere, Category = "Robbing|Vision")
		UStaticMeshComponent* VisionMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robbin | General", meta=(AllowPrivateAccess="true"))
	UBehaviorTree* EnemyBehaviorTree;
		
	UPROPERTY()
	UBlackboardComponent* pMyBlackboardComponent;

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robbin | General", meta = (AllowPrivateAccess = "true"))
	APatrolPath* PatrolPath;
};

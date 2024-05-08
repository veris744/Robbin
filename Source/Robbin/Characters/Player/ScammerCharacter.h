// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayableCharacter.h"
#include "ScammerCharacter.generated.h"

class ASuspiciousBag;

/**
 * 
 */
UCLASS()
class ROBBIN_API AScammerCharacter : public APlayableCharacter
{
	GENERATED_BODY()

public:
	AScammerCharacter()
	{
		Type = CharacterType::SCAMMER;
	}
	
	UPROPERTY()
		ASuspiciousBag* SuspiciousBag = nullptr;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robbing|Abilities", meta = (DisplayName = "Bag Class"))
		TSubclassOf<class ASuspiciousBag> BagClass;

	UPROPERTY(EditAnywhere, Category = "Robbing|Abilities")
		float LeaveBagRange = 500;

protected:

	virtual void DoAbility1() override;

	virtual void DoAbility2() override;

	virtual void DoAbility3() override;

	virtual void DoAbility4() override;

	virtual void DoAbility5() override;

	virtual void DoAbility6() override;

	virtual void DoAbility7() override;
};

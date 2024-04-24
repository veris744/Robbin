// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayableCharacter.h"
#include "ScammerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ROBBIN_API AScammerCharacter : public APlayableCharacter
{
	GENERATED_BODY()
	
protected:

	virtual void DoAbility1() override;

	virtual void DoAbility2() override;

	virtual void DoAbility3() override;

	virtual void DoAbility4() override;

	virtual void DoAbility5() override;

	virtual void DoAbility6() override;

	virtual void DoAbility7() override;
};

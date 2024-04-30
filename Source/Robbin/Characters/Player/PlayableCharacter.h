// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Robbin/Characters/GenericCharacter.h"
#include "PlayableCharacter.generated.h"

class AInteractiveActor;
class UStaticAbilities;

UENUM()
enum class CharacterType
{
	TECH,
	SPY,
	SCAMMER
};

static FString GetStringFromCharacterType(CharacterType Type)
{
	switch (Type)
	{
	case CharacterType::TECH:
		return "TECH";
		break;
	case CharacterType::SPY:
		return "SPY";
		break;
	case CharacterType::SCAMMER:
		return "SCAM";
		break;
	default:
		return "NONE";
		break;
	}
}

static FString GetStringFromCharacterType(int _Type)
{
	CharacterType Type = StaticCast<CharacterType>(_Type);
	switch (Type)
	{
	case CharacterType::TECH:
		return "TECH";
		break;
	case CharacterType::SPY:
		return "SPY";
		break;
	case CharacterType::SCAMMER:
		return "SCAM";
		break;
	default:
		return "NONE";
		break;
	}
}

/**
 * 
 */
UCLASS()
class ROBBIN_API APlayableCharacter : public AGenericCharacter
{
	GENERATED_BODY()

public:
	APlayableCharacter();

	virtual void BeginPlay() override;

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }


	UFUNCTION()
		void ExecuteAbility(UAbility* ability, AInteractiveActor* InteractiveActor = nullptr);

	UPROPERTY()
		TArray<FString> Abilities;

	UPROPERTY()
		CharacterType Type;

protected:

	UFUNCTION()
		virtual void DoAbility1() {};

	UFUNCTION()
		virtual void DoAbility2() {};

	UFUNCTION()
		virtual void DoAbility3() {};

	UFUNCTION()
		virtual void DoAbility4() {};

	UFUNCTION()
		virtual void DoAbility5() {};

	UFUNCTION()
		virtual void DoAbility6() {};

	UFUNCTION()
		virtual void DoAbility7() {};

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
	
		UPROPERTY(VisibleAnywhere)
		class UAIPerceptionStimuliSourceComponent* StimulusSource;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual void AddMovementInput(FVector WorldDirection, float ScaleValue = 1.0f, bool bForce = false) override;
	
	void SetupStimulusSource();

	UPROPERTY()
	UStaticAbilities* AbilitiesManager;
};

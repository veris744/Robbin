// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Robbin/Characters/GenericCharacter.h"
#include "RobbinPlayerController.h"
#include "PlayableCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ROBBIN_API APlayableCharacter : public AGenericCharacter
{
	GENERATED_BODY()

public:
	APlayableCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }


	UFUNCTION()
		void ExecuteAbility(AbilityOn Ability);


	UFUNCTION()
		virtual void DoAbility1() {};

	UFUNCTION()
		virtual void DoAbility2() { GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Ability2")); };

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

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

	virtual void AddMovementInput(FVector WorldDirection, float ScaleValue = 1.0f, bool bForce = false) override;
};

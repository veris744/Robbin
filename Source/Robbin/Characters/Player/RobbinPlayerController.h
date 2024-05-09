// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "Robbin/Abilities/Ability.h"
#include "PlayableCharacter.h"
#include "RobbinPlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;
class UInputMappingContext;
class UInputAction;
class ATechCharacter;
class ASpyCharacter;
class AScammerCharacter;
class UStaticAbilities;


DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS()
class ARobbinPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ARobbinPlayerController();

	UPROPERTY()
		UStaticAbilities* AbilitiesManager;

	/** Time Threshold to know if it was a short press */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold;

	/** FX Class that we will spawn when clicking */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UNiagaraSystem* FXCursor;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;
	

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;
	
	///////////////////////////////////////////////////
	//////////// ABILITY INPUT ACTIONS ////////////////
	///////////////////////////////////////////////////

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input|Abilities", meta = (AllowPrivateAccess = "true"))
	UInputAction* StartAbility1Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Abilities", meta = (AllowPrivateAccess = "true"))
	UInputAction* StartAbility2Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Abilities", meta = (AllowPrivateAccess = "true"))
	UInputAction* StartAbility3Action;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Abilities", meta = (AllowPrivateAccess = "true"))
	UInputAction* StartAbility4Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Abilities", meta = (AllowPrivateAccess = "true"))
	UInputAction* StartAbility5Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Abilities", meta = (AllowPrivateAccess = "true"))
	UInputAction* StartAbility6Action;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Abilities", meta = (AllowPrivateAccess = "true"))
	UInputAction* StartAbility7Action;



	///////////////////////////////////////////////////
	//////////// CHARACTER INPUT ACTION ///////////////
	///////////////////////////////////////////////////

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Characters", meta = (AllowPrivateAccess = "true"))
		UInputAction* SetCharacterTech;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Characters", meta = (AllowPrivateAccess = "true"))
		UInputAction* SetCharacterSpy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Characters", meta = (AllowPrivateAccess = "true"))
		UInputAction* SetCharacterScam;


	///////////////////////////////////////////////////
	///////////// MOVEMENT INPUT ACTION ///////////////
	///////////////////////////////////////////////////

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Movement", meta = (AllowPrivateAccess = "true"))
		UInputAction* SetDestinationClickAction;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Movement", meta = (AllowPrivateAccess = "true"))
		UInputAction* RotateRAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Movement", meta = (AllowPrivateAccess = "true"))
		UInputAction* RotateLAction;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Movement", meta = (AllowPrivateAccess = "true"))
		UInputAction* ZoomInAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Movement", meta = (AllowPrivateAccess = "true"))
		UInputAction* ZoomOutAction;



	///////////////////////////////////////////////////
	/////////////// CHARACTER CLASSES /////////////////
	///////////////////////////////////////////////////

	UPROPERTY(EditAnywhere, Category = "Robbing|Characters")
		APlayableCharacter* TechCharacter;

	UPROPERTY(EditAnywhere, Category = "Robbing|Characters")
		APlayableCharacter* SpyCharacter;

	UPROPERTY(EditAnywhere, Category = "Robbing|Characters")
		APlayableCharacter* ScamCharacter;


	///////////////////////////////////////////////////
	//////////////////// STATE ////////////////////////
	///////////////////////////////////////////////////

	UPROPERTY(VisibleAnywhere, Category = "Robbing|Abilities")
		UAbility* ActiveAbility;

	UPROPERTY(EditAnywhere, Category = "Robbing|Characters")
		CharacterType CurrentType;

	UFUNCTION()
		APlayableCharacter* GetCurrentCharacter();


	///////////////////////////////////////////////////
	//////////////////// HUD //////////////////////////
	///////////////////////////////////////////////////

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robbing|UI", meta = (DisplayName = "HUD Class"))
		TSubclassOf<class UMainUserWidget> HUDClass;

	UPROPERTY(VisibleAnywhere, Category = "Robbing|UI", Transient)
		class UMainUserWidget* HUDWidget;



protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	virtual void SetupInputComponent() override;
	
	// To add mapping context
	virtual void BeginPlay();


	///////////////////////////////////////////////////
	///////////// INPUT FUNCTIONS /////////////////////
	///////////////////////////////////////////////////

	void OnInputStarted();
	void OnSetDestinationTriggered();
	void OnSetDestinationReleased();

	void OnSetRotateRTriggered();
	void OnSetRotateLTriggered();
	void OnSetZoomInTriggered();
	void OnSetZoomOutTriggered();

public:
	void OnUseUAbility1();
	void OnUseUAbility2();
	void OnUseUAbility3();
	void OnUseUAbility4();
	void OnUseUAbility5();
	void OnUseUAbility6();
	void OnUseUAbility7();

	void OnChangeCharacterTech();
	void OnChangeCharacterSpy();
	void OnChangeCharacterScam();


private:

	///////////////////////////////////////////////////
	/////////////////// INTERNAL //////////////////////
	///////////////////////////////////////////////////

	FVector CachedDestination;

	bool bIsTouch; // Is it a touch device
	float FollowTime; // For how long it has been pressed

	AActor* DestinationActor;



	FString FindAbilityId(CharacterType Type, int num);
};



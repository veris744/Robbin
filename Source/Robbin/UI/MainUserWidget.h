// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUserWidget.generated.h"


class UButton;
class UListView;
class ARobbinPlayerController;



/**
 * 
 */
UCLASS()
class ROBBIN_API UMainUserWidget : public UUserWidget
{
	GENERATED_BODY()



public:



	virtual void NativeConstruct() override;

	UPROPERTY()
	ARobbinPlayerController* PlayerController;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robbing|Menu", meta = (DisplayName = "HUD Class"))
		TSubclassOf<class UMenuItem> ItemClass;


	//CHANGE CHARACTER BUTTONS

	UPROPERTY(meta = (BindWidget))
	UButton* TechCharacterButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SpyCharacterButton;

	UPROPERTY(meta = (BindWidget))
	UButton* ScamCharacterButton;


	//USE ABILITIES BUTTONS

	UPROPERTY(meta = (BindWidget))
		UButton* Ability1Button;

	UPROPERTY(meta = (BindWidget))
		UButton* Ability2Button;

	UPROPERTY(meta = (BindWidget))
		UButton* Ability3Button;

	UPROPERTY(meta = (BindWidget))
		UButton* Ability4Button;

	UPROPERTY(meta = (BindWidget))
		UButton* Ability5Button;

	UPROPERTY(meta = (BindWidget))
		UButton* Ability6Button;

	UPROPERTY(meta = (BindWidget))
		UButton* Ability7Button;


	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UListView* ActionsList;

	UPROPERTY(BlueprintReadWrite)
		TArray<FString> TempTexts;

	UPROPERTY(meta = (BindWidget))
		UButton* ExitCameraButton;

	UFUNCTION()
		void setCharacterColor(CharacterType CurrentCharacterType);

	UFUNCTION()
		void SetAbilityButtonColor(int nAbility);

	UFUNCTION()
	void ShowActionsMenu(AInteractiveActor* actor);

	void SetGameMode();

	void SetCameraMode();

private:

	//CHANGE CHARACTER FUNCTIONS

	UFUNCTION()
		void OnClickedTech();

	UFUNCTION()
		void OnClickedSpy();

	UFUNCTION()
		void OnClickedScam();


	//USE ABILITIES FUNCTIONS

	UFUNCTION()
		void OnClickedA1();

	UFUNCTION()
		void OnClickedA2();

	UFUNCTION()
		void OnClickedA3();

	UFUNCTION()
		void OnClickedA4();

	UFUNCTION()
		void OnClickedA5();

	UFUNCTION()
		void OnClickedA6();

	UFUNCTION()
		void OnClickedA7();

	UFUNCTION()
		void OnExitCamera();


	FColor SelectedColor = FColor::Cyan;

	FColor NonSelectedColor = FColor(30,30,30);
};

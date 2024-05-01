// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/ProgressBar.h>
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

	bool bInGameMode = true;

	///////////////////////////////////////////////////
	////////////// CHARACTER BUTTONS //////////////////
	///////////////////////////////////////////////////

	UPROPERTY(meta = (BindWidget))
	UButton* TechCharacterButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SpyCharacterButton;

	UPROPERTY(meta = (BindWidget))
	UButton* ScamCharacterButton;


	///////////////////////////////////////////////////
	////////////// ABILITIES BUTTONS //////////////////
	///////////////////////////////////////////////////

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


	///////////////////////////////////////////////////
	/////////////////// SUSPICION /////////////////////
	///////////////////////////////////////////////////


	UPROPERTY(meta = (BindWidget))
		UProgressBar* SuspicionLevel;

	UFUNCTION()
		void SetSuspicionLevelBar(float Percentage);

	///////////////////////////////////////////////////
	/////////////////// ACTIONS MENU //////////////////
	///////////////////////////////////////////////////


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robbing|Menu", meta = (DisplayName = "HUD Class"))
		TSubclassOf<class UMenuItem> ItemClass;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UListView* ActionsList;

	UPROPERTY(BlueprintReadOnly)
		TArray<FString> TempTexts;

	UPROPERTY(BlueprintReadOnly)
		AInteractiveActor* DisplayedInteractive;

	UFUNCTION()
		void ShowActionsMenu(AInteractiveActor* actor);


	///////////////////////////////////////////////////
	///////////////// CAMERA OPTIONS //////////////////
	///////////////////////////////////////////////////

	UPROPERTY(meta = (BindWidget))
		UButton* ExitCameraButton;


	///////////////////////////////////////////////////
	//////////////////// SETTING //////////////////////
	///////////////////////////////////////////////////

	UFUNCTION()
		void setCharacterColor(CharacterType CurrentCharacterType);

	UFUNCTION()
		void SetAbilityButtonColor(int nAbility);

	UFUNCTION(BlueprintCallable)
		void SetMenuClickedFunctions(UMenuItem* MenuItem, FString NameElement);

	void SetGameMode();

	void SetCameraMode();


private:

	///////////////////////////////////////////////////
	////////// BUTTON CHARACTER FUNCTION //////////////
	///////////////////////////////////////////////////

	UFUNCTION()
		void OnClickedTech();

	UFUNCTION()
		void OnClickedSpy();

	UFUNCTION()
		void OnClickedScam();


	///////////////////////////////////////////////////
	////////// BUTTON ABILITIES FUNCTION //////////////
	///////////////////////////////////////////////////

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



	///////////////////////////////////////////////////
	/////////////// DEFAULT VALUES ////////////////////
	///////////////////////////////////////////////////

	FColor SelectedColor = FColor::Cyan;

	FColor NonSelectedColor = FColor(30,30,30);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <CommonListView.h>
#include "DialogueWidget.generated.h"

/**
 * 
 */
UCLASS()
class ROBBIN_API UDialogueWidget : public UUserWidget
{
	GENERATED_BODY()


	///////////////////////////////////////////////////
	/////////////////// ACTIONS MENU //////////////////
	///////////////////////////////////////////////////

public:

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robbing|Menu", meta = (DisplayName = "Item Class"))
	TSubclassOf<class UMenuItem> ItemClass;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UListView* ActionsList;

	UPROPERTY(BlueprintReadOnly)
		TArray<FString> TempTexts;

	UFUNCTION()
	void ShowActionsMenu();

	void EmptyActionsMenu();*/
};

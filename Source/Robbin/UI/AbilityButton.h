// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AbilityButton.generated.h"

class UButton;
class UBorder;
class UCommonTextBlock;
class ARobbinPlayerController;
class UMainUserWidget;
class UAbility;
class UTextBlock;

/**
 * 
 */
UCLASS()
class ROBBIN_API UAbilityButton : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* AbilityButton;

	UAbility* Ability;

	UFUNCTION()
	void OnClicked();

	UFUNCTION()
	void OnHovered();

	UFUNCTION()
	void OnUnhovered();


	UPROPERTY(meta = (BindWidget))
		UTextBlock* ButtonText;


	UPROPERTY(meta = (BindWidget))
		UBorder* DescriptionBorder;

	UPROPERTY(meta = (BindWidget))
		UCommonTextBlock* AbilityDescriptionText;


	void ShowAbilityDescription(bool bShow, FString Text = "");

	void SetButtonColor(FColor Color);

	UPROPERTY()
		UMainUserWidget* HUDWidget;


};

// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityButton.h"
#include <Components/Button.h>
#include "CommonTextBlock.h"
#include <Components/Border.h>
#include <Components/TextBlock.h>
#include "MainUserWidget.h"
#include <Robbin/Abilities/StaticAbilities.h>
#include <Robbin/Abilities/Ability.h>
#include <Robbin/Characters/Player/RobbinPlayerController.h>

void UAbilityButton::NativeConstruct()
{
	AbilityButton->OnClicked.AddDynamic(this, &UAbilityButton::OnClicked);
	AbilityButton->OnHovered.AddDynamic(this, &UAbilityButton::OnHovered);
	AbilityButton->OnUnhovered.AddDynamic(this, &UAbilityButton::OnUnhovered);
	
	DescriptionBorder->SetVisibility(ESlateVisibility::Hidden);
	AbilityDescriptionText->SetText(FText::FromString(""));
	ButtonText->SetText(FText::FromString(""));
}

void UAbilityButton::OnClicked()
{
	if (HUDWidget && HUDWidget->PlayerController)
	{
		if (Ability->AbilityNo == AbilityNumber::ABILITY1)
			HUDWidget->PlayerController->OnUseUAbility1();

		else if (Ability->AbilityNo == AbilityNumber::ABILITY2)
			HUDWidget->PlayerController->OnUseUAbility2();

		else if (Ability->AbilityNo == AbilityNumber::ABILITY3)
			HUDWidget->PlayerController->OnUseUAbility3();

		else if (Ability->AbilityNo == AbilityNumber::ABILITY4)
			HUDWidget->PlayerController->OnUseUAbility4();

		else if (Ability->AbilityNo == AbilityNumber::ABILITY5)
			HUDWidget->PlayerController->OnUseUAbility5();

		else if (Ability->AbilityNo == AbilityNumber::ABILITY6)
			HUDWidget->PlayerController->OnUseUAbility6();

		else if (Ability->AbilityNo == AbilityNumber::ABILITY7)
			HUDWidget->PlayerController->OnUseUAbility7();

	}
}

void UAbilityButton::OnHovered()
{
	FString desc = Ability->Description;
	ShowAbilityDescription(true, desc);
}

void UAbilityButton::OnUnhovered()
{
	ShowAbilityDescription(false);
}


void UAbilityButton::ShowAbilityDescription(bool bShow, FString Text)
{
	if (bShow)
	{
		AbilityDescriptionText->SetText(FText::FromString(Text));
		DescriptionBorder->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		DescriptionBorder->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UAbilityButton::SetButtonColor(FColor Color)
{
	AbilityButton->SetBackgroundColor(Color);
}

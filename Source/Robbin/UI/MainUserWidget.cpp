// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUserWidget.h"
#include "Robbin/Characters/Player/RobbinPlayerController.h"
#include "Robbin/InteractiveActors/InteractiveActor.h"
#include <Components/Button.h>
#include <Components/Border.h>
#include <Components/TextBlock.h>
#include "Components/ListView.h"
#include <Robbin/Abilities/StaticAbilities.h>
#include "MenuItem.h"
#include "CommonTextBlock.h"
#include "AbilityButton.h"

void UMainUserWidget::NativeConstruct()
{

	Super::NativeConstruct();

	TechCharacterButton->OnClicked.AddDynamic(this, &UMainUserWidget::OnClickedTech);
	SpyCharacterButton->OnClicked.AddDynamic(this, &UMainUserWidget::OnClickedSpy);
	ScamCharacterButton->OnClicked.AddDynamic(this, &UMainUserWidget::OnClickedScam);

	ExitCameraButton->OnClicked.AddDynamic(this, &UMainUserWidget::OnExitCamera);

	SetGameMode();
	SetAbilityButtonColor(0);

	SuspicionLevel->SetPercent(0);

	TTBorder->SetVisibility(ESlateVisibility::Hidden);
	TTText->SetText(FText::FromString(""));


	//Setup Ability Buttons
	Ability1Button->HUDWidget = this;
	Ability2Button->HUDWidget = this;
	Ability3Button->HUDWidget = this;
	Ability4Button->HUDWidget = this;
	Ability5Button->HUDWidget = this;
	Ability6Button->HUDWidget = this;
	Ability7Button->HUDWidget = this;

	Ability1Button->ButtonText->SetText(FText::FromString("1"));
	Ability2Button->ButtonText->SetText(FText::FromString("2"));
	Ability3Button->ButtonText->SetText(FText::FromString("3"));
	Ability4Button->ButtonText->SetText(FText::FromString("4"));
	Ability5Button->ButtonText->SetText(FText::FromString("5"));
	Ability6Button->ButtonText->SetText(FText::FromString("6"));
	Ability7Button->ButtonText->SetText(FText::FromString("7"));
}


void UMainUserWidget::ShowTT(bool bShow, FString Text)
{
	if (bShow)
	{
		TTText->SetText(FText::FromString(Text));
		UpdateWidgetPosition(TTBorder, TTBorder->GetDesiredSize());
		TTBorder->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		TTBorder->SetVisibility(ESlateVisibility::Hidden);
	}
}

bool UMainUserWidget::IsTTShown()
{
	if (TTBorder->GetVisibility() == ESlateVisibility::Visible)
		return true;

	return false;
}

void UMainUserWidget::UpdateWidgetPosition(UWidget* Widget, FVector2D Size)
{
	FVector2D Mouse2D;
	PlayerController->GetMousePosition(Mouse2D.X, Mouse2D.Y);

	int x, y;
	PlayerController->GetViewportSize(x, y);
	FVector2D vp = FVector2D(x, y);

	FVector2D res;
	res.X = 1920;
	res.Y = 1080;

	FVector2D fin = Mouse2D * res / vp - (res / 2);

	if (fin.X > 0)
	{
		fin.X -= Size.X;
	}

	if (fin.Y > 0)
	{
		fin.Y -= Size.Y;
	}
	else
	{
		fin.Y += Size.Y / 4;
	}

	Widget->SetRenderTranslation(fin);

}

void UMainUserWidget::SetCharacterColor(CharacterType CurrentCharacterType)
{
	switch (CurrentCharacterType)
	{
	case CharacterType::TECH:
	{
		TechCharacterButton->SetBackgroundColor(SelectedColor);
		SpyCharacterButton->SetBackgroundColor(NonSelectedColor);
		ScamCharacterButton->SetBackgroundColor(NonSelectedColor);
	}
	break;
	case CharacterType::SPY:
	{
		TechCharacterButton->SetBackgroundColor(NonSelectedColor);
		SpyCharacterButton->SetBackgroundColor(SelectedColor);
		ScamCharacterButton->SetBackgroundColor(NonSelectedColor);
	}
	break;
	case CharacterType::SCAMMER:
	{
		TechCharacterButton->SetBackgroundColor(NonSelectedColor);
		SpyCharacterButton->SetBackgroundColor(NonSelectedColor);
		ScamCharacterButton->SetBackgroundColor(SelectedColor);
	}
	break;
	default:
		break;
	}
}

void UMainUserWidget::SetAbilityButtonColor(int nAbility)
{
	Ability1Button->SetButtonColor(NonSelectedColor);
	Ability2Button->SetButtonColor(NonSelectedColor);
	Ability3Button->SetButtonColor(NonSelectedColor);
	Ability4Button->SetButtonColor(NonSelectedColor);
	Ability5Button->SetButtonColor(NonSelectedColor);
	Ability6Button->SetButtonColor(NonSelectedColor);
	Ability7Button->SetButtonColor(NonSelectedColor);

	if (nAbility == 0)	return;

	if (nAbility == 1)
		Ability1Button->SetButtonColor(SelectedColor);
	else if (nAbility == 2)
		Ability2Button->SetButtonColor(SelectedColor);
	else if (nAbility == 3)
		Ability3Button->SetButtonColor(SelectedColor);
	else if (nAbility == 4)
		Ability4Button->SetButtonColor(SelectedColor);
	else if (nAbility == 5)
		Ability5Button->SetButtonColor(SelectedColor);
	else if (nAbility == 6)
		Ability6Button->SetButtonColor(SelectedColor);
	else if (nAbility == 7)
		Ability7Button->SetButtonColor(SelectedColor);
}

void UMainUserWidget::SetButtonsAbilities()
{
	if (PlayerController->CurrentType == CharacterType::TECH)
	{
		Ability1Button->Ability = PlayerController->AbilitiesManager->GetFromId("TECH1");
		Ability2Button->Ability = PlayerController->AbilitiesManager->GetFromId("TECH2");
		Ability3Button->Ability = PlayerController->AbilitiesManager->GetFromId("TECH3");
		Ability4Button->Ability = PlayerController->AbilitiesManager->GetFromId("TECH4");
		Ability5Button->Ability = PlayerController->AbilitiesManager->GetFromId("TECH5");
		Ability6Button->Ability = PlayerController->AbilitiesManager->GetFromId("TECH6");
		Ability7Button->Ability = PlayerController->AbilitiesManager->GetFromId("TECH7");
	}

	if (PlayerController->CurrentType == CharacterType::SPY)
	{
		Ability1Button->Ability = PlayerController->AbilitiesManager->GetFromId("SPY1");
		Ability2Button->Ability = PlayerController->AbilitiesManager->GetFromId("SPY2");
		Ability3Button->Ability = PlayerController->AbilitiesManager->GetFromId("SPY3");
		Ability4Button->Ability = PlayerController->AbilitiesManager->GetFromId("SPY4");
		Ability5Button->Ability = PlayerController->AbilitiesManager->GetFromId("SPY5");
		Ability6Button->Ability = PlayerController->AbilitiesManager->GetFromId("SPY6");
		Ability7Button->Ability = PlayerController->AbilitiesManager->GetFromId("SPY7");
	}

	if (PlayerController->CurrentType == CharacterType::SCAMMER)
	{
		Ability1Button->Ability = PlayerController->AbilitiesManager->GetFromId("SCAM1");
		Ability2Button->Ability = PlayerController->AbilitiesManager->GetFromId("SCAM2");
		Ability3Button->Ability = PlayerController->AbilitiesManager->GetFromId("SCAM3");
		Ability4Button->Ability = PlayerController->AbilitiesManager->GetFromId("SCAM4");
		Ability5Button->Ability = PlayerController->AbilitiesManager->GetFromId("SCAM5");
		Ability6Button->Ability = PlayerController->AbilitiesManager->GetFromId("SCAM6");
		Ability7Button->Ability = PlayerController->AbilitiesManager->GetFromId("SCAM7");
	}
}

void UMainUserWidget::SetSuspicionLevelBar(float Percentage)
{
	SuspicionLevel->SetPercent(Percentage/100);
}

void UMainUserWidget::ShowActionsMenu(AInteractiveActor* actor)
{
	if (!actor)	return;


	ShowTT(false);

	DisplayedInteractive = actor;
	PlayerController->SetInputMode(FInputModeUIOnly());
	bInGameMode = false;
	
	TArray<FString> abis;
	actor->DisplayableActions.GetKeys(abis);

	for (FString ability : abis)
	{
		UMenuItem* item1 = CreateWidget<UMenuItem>(this, ItemClass);
		ActionsList->AddItem(item1);
		TempTexts.Add(ability);
	}


	Ability1Button->SetVisibility(ESlateVisibility::HitTestInvisible);
	Ability2Button->SetVisibility(ESlateVisibility::HitTestInvisible);
	Ability3Button->SetVisibility(ESlateVisibility::HitTestInvisible);
	Ability4Button->SetVisibility(ESlateVisibility::HitTestInvisible);
	Ability5Button->SetVisibility(ESlateVisibility::HitTestInvisible);
	Ability6Button->SetVisibility(ESlateVisibility::HitTestInvisible);
	Ability7Button->SetVisibility(ESlateVisibility::HitTestInvisible);

}


void UMainUserWidget::SetMenuClickedFunctions(UMenuItem* MenuItem, FString NameElement)
{
	MenuItem->Function = DisplayedInteractive->DisplayableActions[NameElement];
}

void UMainUserWidget::SetGameMode()
{
	if (PlayerController)
	{
		FInputModeGameAndUI inputMode;
		inputMode.SetHideCursorDuringCapture(false);
		PlayerController->SetInputMode(inputMode);
	}

	bInGameMode = true;

	TechCharacterButton->SetVisibility(ESlateVisibility::Visible);
	SpyCharacterButton->SetVisibility(ESlateVisibility::Visible);
	ScamCharacterButton->SetVisibility(ESlateVisibility::Visible);

	Ability1Button->SetVisibility(ESlateVisibility::Visible);
	Ability2Button->SetVisibility(ESlateVisibility::Visible);
	Ability3Button->SetVisibility(ESlateVisibility::Visible);
	Ability4Button->SetVisibility(ESlateVisibility::Visible);
	Ability5Button->SetVisibility(ESlateVisibility::Visible);
	Ability6Button->SetVisibility(ESlateVisibility::Visible);
	Ability7Button->SetVisibility(ESlateVisibility::Visible);

	ExitCameraButton->SetVisibility(ESlateVisibility::Hidden);

	ActionsList->ClearListItems();
}

void UMainUserWidget::SetCameraMode()
{
	bInGameMode = false;

	TechCharacterButton->SetVisibility(ESlateVisibility::Hidden);
	SpyCharacterButton->SetVisibility(ESlateVisibility::Hidden);
	ScamCharacterButton->SetVisibility(ESlateVisibility::Hidden);

	Ability1Button->SetVisibility(ESlateVisibility::Hidden);
	Ability2Button->SetVisibility(ESlateVisibility::Hidden);
	Ability3Button->SetVisibility(ESlateVisibility::Hidden);
	Ability4Button->SetVisibility(ESlateVisibility::Hidden);
	Ability5Button->SetVisibility(ESlateVisibility::Hidden);
	Ability6Button->SetVisibility(ESlateVisibility::Hidden);
	Ability7Button->SetVisibility(ESlateVisibility::Hidden);

	ExitCameraButton->SetVisibility(ESlateVisibility::Visible);
}


void UMainUserWidget::OnClickedTech()
{
	if (PlayerController)
	{
		PlayerController->OnChangeCharacterTech();
	}
}

void UMainUserWidget::OnClickedSpy()
{
	if (PlayerController)
	{
		PlayerController->OnChangeCharacterSpy();
	}
}

void UMainUserWidget::OnClickedScam()
{
	if (PlayerController)
	{
		PlayerController->OnChangeCharacterScam();
	}
}

void UMainUserWidget::OnExitCamera()
{
	SetGameMode();
	PlayerController->SetViewTarget(PlayerController->GetCharacter());
}

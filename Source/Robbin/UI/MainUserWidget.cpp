// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUserWidget.h"
#include "Robbin/Characters/Player/RobbinPlayerController.h"
#include "Robbin/InteractiveActors/InteractiveActor.h"
#include <Components/Button.h>
#include "Components/ListView.h"
#include <Robbin/Abilities/StaticAbilities.h>
#include "MenuItem.h"


void UMainUserWidget::NativeConstruct()
{

	Super::NativeConstruct();

	TechCharacterButton->OnClicked.AddDynamic(this, &UMainUserWidget::OnClickedTech);
	SpyCharacterButton->OnClicked.AddDynamic(this, &UMainUserWidget::OnClickedSpy);
	ScamCharacterButton->OnClicked.AddDynamic(this, &UMainUserWidget::OnClickedScam);


	Ability1Button->OnClicked.AddDynamic(this, &UMainUserWidget::OnClickedA1);
	Ability2Button->OnClicked.AddDynamic(this, &UMainUserWidget::OnClickedA2);
	Ability3Button->OnClicked.AddDynamic(this, &UMainUserWidget::OnClickedA3);
	Ability4Button->OnClicked.AddDynamic(this, &UMainUserWidget::OnClickedA4);
	Ability5Button->OnClicked.AddDynamic(this, &UMainUserWidget::OnClickedA5);
	Ability6Button->OnClicked.AddDynamic(this, &UMainUserWidget::OnClickedA6);
	Ability7Button->OnClicked.AddDynamic(this, &UMainUserWidget::OnClickedA7);

	ExitCameraButton->OnClicked.AddDynamic(this, &UMainUserWidget::OnExitCamera);

	SetGameMode();
	SetAbilityButtonColor(0);

}


void UMainUserWidget::setCharacterColor(CharacterType CurrentCharacterType)
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
	Ability1Button->SetBackgroundColor(NonSelectedColor);
	Ability2Button->SetBackgroundColor(NonSelectedColor);
	Ability3Button->SetBackgroundColor(NonSelectedColor);
	Ability4Button->SetBackgroundColor(NonSelectedColor);
	Ability5Button->SetBackgroundColor(NonSelectedColor);
	Ability6Button->SetBackgroundColor(NonSelectedColor);
	Ability7Button->SetBackgroundColor(NonSelectedColor);

	if (nAbility == 0)	return;

	if (nAbility == 1)
		Ability1Button->SetBackgroundColor(SelectedColor);
	else if (nAbility == 2)
		Ability2Button->SetBackgroundColor(SelectedColor);
	else if (nAbility == 3)
		Ability3Button->SetBackgroundColor(SelectedColor);
	else if (nAbility == 4)
		Ability4Button->SetBackgroundColor(SelectedColor);
	else if (nAbility == 5)
		Ability5Button->SetBackgroundColor(SelectedColor);
	else if (nAbility == 6)
		Ability6Button->SetBackgroundColor(SelectedColor);
	else if (nAbility == 7)
		Ability7Button->SetBackgroundColor(SelectedColor);
}

void UMainUserWidget::ShowActionsMenu(AInteractiveActor* actor)
{
	DisplayedInteractive = actor;
	PlayerController->SetInputMode(FInputModeUIOnly());
	
	TArray<FString> abis;
	actor->DisplayableActions.GetKeys(abis);

	for (FString ability : abis)
	{
		UMenuItem* item1 = CreateWidget<UMenuItem>(this, ItemClass);
		ActionsList->AddItem(item1);
		TempTexts.Add(ability);
	}
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

void UMainUserWidget::OnClickedA1()
{
	if (PlayerController)
	{
		PlayerController->OnUseUAbility1();
	}
}

void UMainUserWidget::OnClickedA2()
{
	if (PlayerController)
	{
		PlayerController->OnUseUAbility2();
	}
}

void UMainUserWidget::OnClickedA3()
{
	if (PlayerController)
	{
		PlayerController->OnUseUAbility3();
	}
}

void UMainUserWidget::OnClickedA4()
{
	if (PlayerController)
	{
		PlayerController->OnUseUAbility4();
	}
}

void UMainUserWidget::OnClickedA5()
{
	if (PlayerController)
	{
		PlayerController->OnUseUAbility5();
	}
}

void UMainUserWidget::OnClickedA6()
{
	if (PlayerController)
	{
		PlayerController->OnUseUAbility6();
	}
}

void UMainUserWidget::OnClickedA7()
{
	if (PlayerController)
	{
		PlayerController->OnUseUAbility7();
	}
}

void UMainUserWidget::OnExitCamera()
{
	SetGameMode();
	PlayerController->SetViewTarget(PlayerController->GetCharacter());
}

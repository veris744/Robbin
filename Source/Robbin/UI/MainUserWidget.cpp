// Fill out your copyright notice in the Description page of Project Settings.


#include "MainUserWidget.h"
#include "Robbin/Characters/Player/RobbinPlayerController.h"
#include <Components/Button.h>


void UMainUserWidget::NativeConstruct()
{
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

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

void UMainUserWidget::OnClickedTech()
{
	if (PlayerController)
	{
		PlayerController->OnChangeCharacterTech();
		TechCharacterButton->SetBackgroundColor(SelectedColor);
		SpyCharacterButton->SetBackgroundColor(NonSelectedColor);
		ScamCharacterButton->SetBackgroundColor(NonSelectedColor);
	}
}

void UMainUserWidget::OnClickedSpy()
{
	if (PlayerController)
	{
		PlayerController->OnChangeCharacterSpy();
		TechCharacterButton->SetBackgroundColor(NonSelectedColor);
		SpyCharacterButton->SetBackgroundColor(SelectedColor);
		ScamCharacterButton->SetBackgroundColor(NonSelectedColor);
	}
}

void UMainUserWidget::OnClickedScam()
{
	if (PlayerController)
	{
		PlayerController->OnChangeCharacterScam();
		TechCharacterButton->SetBackgroundColor(NonSelectedColor);
		SpyCharacterButton->SetBackgroundColor(NonSelectedColor);
		ScamCharacterButton->SetBackgroundColor(SelectedColor);
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

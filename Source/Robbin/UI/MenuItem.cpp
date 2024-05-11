// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuItem.h"
#include "MainUserWidget.h"

void UMenuItem::NativeConstruct()
{
	Super::NativeConstruct();



	ItemButton->OnClicked.AddDynamic(this, &UMenuItem::OnClicked);

	ItemButton->SetBackgroundColor(FColor(100, 100, 100));
	ItemName->SetText(FText::FromString("dfsfh"));

}


void UMenuItem::SetButtonText(FString _Text)
{
	ItemName->SetText(FText::FromString(_Text));
}

void UMenuItem::SetHud(UMainUserWidget* HUDWidget)
{
	HUD = HUDWidget;
}

void UMenuItem::OnClicked()
{
	if (Function)
	{
		Function();
	}
	if (HUD)
	{
		HUD->SetGameMode();
		HUD->EmptyActionsMenu();
	}
}

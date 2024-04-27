// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuItem.h"

void UMenuItem::NativeConstruct()
{
	Super::NativeConstruct();

	ItemButton->SetBackgroundColor(FColor(100, 100, 100));
	ItemName->SetText(FText::FromString("dfsfh"));
}

void UMenuItem::NativePreConstruct()
{
	Super::NativePreConstruct();

	ItemButton->SetBackgroundColor(FColor(0, 100, 100));
	ItemName->SetText(FText::FromString("asdf"));
}

void UMenuItem::SetButtonText(FString _Text)
{
	ItemName->SetText(FText::FromString(_Text));
}

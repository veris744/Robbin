// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/Button.h>
#include <Components/TextBlock.h>
#include "MenuItem.generated.h"



/**
 * 
 */
UCLASS()
class ROBBIN_API UMenuItem : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* ItemButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemName;


	UFUNCTION()
		void SetButtonText(FString _Text);

};

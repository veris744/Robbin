// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DialogueOption.generated.h"

/**
 * 
 */
UCLASS()
class ROBBIN_API UDialogueOption : public UObject
{
	GENERATED_BODY()

	int ID;

public:
	UDialogueOption() {};

	FString Dialogue;

	TSubclassOf<class AGenericNPC> NPCClass;
	
	FORCEINLINE int GetId() { return ID; };
	FORCEINLINE void SetId(int id) { ID = id; };
};

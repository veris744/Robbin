// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DialogueOption.h"
#include "DialoguesManager.generated.h"

class AGenericNPC;

/**
 * 
 */
UCLASS()
class ROBBIN_API UDialoguesManager : public UObject
{
	GENERATED_BODY()

	int IdCounter = 0;

	UPROPERTY()
	TMap<int, UDialogueOption*> AllDialogues;

	void InstantiateDialogue(FString Dialogue, TSubclassOf<AGenericNPC> NPCClass);

public:

	FORCEINLINE void clear() { AllDialogues.Empty(); };

	void init();
	UDialogueOption* GetFromId(int id);
	TArray<int> GetIdsFromNPCType(TSubclassOf<AGenericNPC> NPCClass);
};

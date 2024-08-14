// Fill out your copyright notice in the Description page of Project Settings.


#include "DialoguesManager.h"
#include "Robbin/Characters/AI/NPCs/GenericNPC.h"

void UDialoguesManager::InstantiateDialogue(FString Dialogue, TSubclassOf<AGenericNPC> NPCClass)
{
	UDialogueOption* temp = NewObject<UDialogueOption>();
	temp->SetId(IdCounter++);
	temp->Dialogue = Dialogue;
	temp->NPCClass = NPCClass;
	AllDialogues.Add(temp->GetId(), temp);
}

void UDialoguesManager::init()
{
	InstantiateDialogue("Dialogue 1", AGenericNPC::StaticClass());
	InstantiateDialogue("Dialogue 2", AGenericNPC::StaticClass());
}

UDialogueOption* UDialoguesManager::GetFromId(int id)
{
	return AllDialogues[id];
}

TArray<int> UDialoguesManager::GetIdsFromNPCType(TSubclassOf<AGenericNPC> NPCClass)
{
	TArray<int> ids;
	for (auto Dialogue : AllDialogues)
	{
		if (NPCClass == Dialogue.Value->NPCClass)
		{
			ids.Add(Dialogue.Key);
		}
	}
	return ids;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "GenericNPC.h"

UBehaviorTree* AGenericNPC::GetBehaviourTree() const
{
	return EnemyBehaviorTree;
}

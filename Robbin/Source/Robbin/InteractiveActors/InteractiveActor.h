// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractiveActor.generated.h"

UCLASS()
class ROBBIN_API AInteractiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractiveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* MeshComponent;

	UFUNCTION()
		void OnBeginMouseOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION()
		void OnEndMouseOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION()
		virtual void Hovering();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		virtual void Activate();
};
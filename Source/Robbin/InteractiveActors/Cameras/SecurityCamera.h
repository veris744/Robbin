// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../InteractiveActor.h"
#include "SecurityCamera.generated.h"

class UCameraComponent;

UCLASS()
class ROBBIN_API ASecurityCamera : public AInteractiveActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASecurityCamera();

	UPROPERTY(VisibleAnywhere, Category = "Robbing")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, Category = "Robbing")
	USpringArmComponent* ArmComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void setCameraView();

	
};

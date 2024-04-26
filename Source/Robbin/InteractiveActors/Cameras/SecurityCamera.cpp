// Fill out your copyright notice in the Description page of Project Settings.


#include "SecurityCamera.h"
#include <Camera/CameraActor.h>
#include <Robbin/Characters/Player/RobbinPlayerController.h>
#include "Camera/CameraComponent.h"
#include <GameFramework/SpringArmComponent.h>
#include "Robbin/UI/MainUserWidget.h"

// Sets default values
ASecurityCamera::ASecurityCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraOne"));
	ArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	ArmComponent->SetupAttachment(RootComponent);
	CameraComponent->SetupAttachment(ArmComponent, USpringArmComponent::SocketName);

	auto SwitchToCamera = [this]()
	{
		setCameraView();
	};


	Actions.Add(FString("TECH3"), SwitchToCamera);

}

// Called when the game starts or when spawned
void ASecurityCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASecurityCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASecurityCamera::setCameraView()
{
	ARobbinPlayerController * pc = Cast<ARobbinPlayerController>(GetWorld()->GetFirstPlayerController());
	pc->SetViewTarget(this);
	pc->HUDWidget->SetCameraMode();

	pc->SetInputMode(FInputModeUIOnly());
}


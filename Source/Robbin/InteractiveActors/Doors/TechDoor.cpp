// Fill out your copyright notice in the Description page of Project Settings.


#include "TechDoor.h"

// Sets default values
ATechDoor::ATechDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	OutMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OutMesh"));
	DoorMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	SetRootComponent(SceneComponent);
	OutMeshComponent->SetupAttachment(RootComponent);
	DoorMeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ATechDoor::BeginPlay()
{
	Super::BeginPlay();

	ClosedLocation = FVector(DoorMeshComponent->GetRelativeLocation().X, 0, 0);
	OpenedLocation = FVector((ClosedLocation + OpenDistance).X, 0, 0);
	if (bIsOpen)
	{
		Target = FVector(OpenedLocation.X, 0, 0);
	}
	else
	{
		Target = FVector(ClosedLocation.X, 0, 0);
	}
	
}

void ATechDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if ((DoorMeshComponent->GetRelativeLocation() - Target).Length() > 5)
	{
		FVector dir = DoorMeshComponent->GetRelativeLocation() - Target;
		dir.Normalize();
		DoorMeshComponent->SetRelativeLocation(
			FVector((DoorMeshComponent->GetRelativeLocation() - dir * 100 * DeltaTime).X, 0, 0));
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%f"), (DoorMeshComponent->GetRelativeLocation() - Target).Length()));
	}
}

void ATechDoor::Open()
{
	bIsOpen = true;
	Target = OpenedLocation;
}

void ATechDoor::Close()
{
	bIsOpen = false;
	Target = ClosedLocation;
}



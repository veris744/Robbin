// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorTech.generated.h"

UCLASS()
class ROBBIN_API ADoorTech : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorTech();

private:
	//UPROPERTY(VisibleAnywhere)
	//	UStaticMeshComponent* OutMeshComponent;


	//UPROPERTY(VisibleAnywhere)
	//	UStaticMeshComponent* DoorMeshComponent;


	//UPROPERTY(VisibleAnywhere)
	//	USceneComponent* SceneComponent;

	//FVector ClosedLocation;
	//FVector OpenedLocation;

	//FVector Target = FVector::Zero();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//UFUNCTION(Category = "Robbing")
	//	void Open();

	//UFUNCTION(Category = "Robbing")
	//	void Close();


	//UPROPERTY(BlueprintReadWrite, Category = "Robbing")
	//	bool bIsOpen = false;


	//UPROPERTY(BlueprintReadWrite, Category = "Robbing")
	//	float OpenDistance = 100;

};

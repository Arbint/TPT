// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SlidingDoor.generated.h"

UCLASS()
class TPT_API ASlidingDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASlidingDoor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	UPROPERTY()
		USceneComponent* RootComp;

	UPROPERTY()
		UStaticMeshComponent* MeshComp;

	UFUNCTION(BlueprintCallable, Category = Door)
		void Open();
	UPROPERTY()
		bool IsOpen;
	UPROPERTY()
		FVector TargetLocation;
	
};

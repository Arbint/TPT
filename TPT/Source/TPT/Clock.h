// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Clock.generated.h"

UCLASS()
class TPT_API AClock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClock();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY()
		USceneComponent* RootSceneComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
		UStaticMeshComponent* ClockFace;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
		USceneComponent* HourHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
		UStaticMeshComponent* HourHand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
		USceneComponent* MinuteHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
		UStaticMeshComponent* MinuteHand;

	UFUNCTION()
		void TimeChanged(int32 Hours, int32 Minutes);

	FDelegateHandle MyDelegateHandle;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TimeOfTheDayHandler.generated.h"


DECLARE_MULTICAST_DELEGATE_TwoParams(FOntimeChagedSignature, int32, int32)

UCLASS()
class TPT_API ATimeOfTheDayHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeOfTheDayHandler();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	FOntimeChagedSignature OnTimeChanged;
	
	UPROPERTY()
		int32 TimeScale;

	UPROPERTY()
		int32 Hours;

	UPROPERTY()
		int32 Minutes;

	UPROPERTY()
		float ElapsedSeconds;
	
};

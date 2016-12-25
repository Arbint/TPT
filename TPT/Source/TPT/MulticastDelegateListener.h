// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MulticastDelegateListener.generated.h"

UCLASS()
class TPT_API AMulticastDelegateListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMulticastDelegateListener();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION()
		void ToggleLight();

	UFUNCTION()
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY()
		UPointLightComponent* PointLight;
	
	FDelegateHandle MydelegateHandle;
	

};

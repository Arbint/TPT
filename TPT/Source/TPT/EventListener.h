// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "EventListener.generated.h"


class ATriggerActor;

UCLASS()
class TPT_API AEventListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEventListener();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY()
		UPointLightComponent* PointLight;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fun")
		ATriggerActor* TriggerEventSource;

	UFUNCTION()
		void OnTriggerEvent();
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TriggerActor.generated.h"

DECLARE_EVENT(ATriggerActor, FPlayerEntered)

UCLASS()
class TPT_API ATriggerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigger")
		USphereComponent* SphereTrigger;

	UPROPERTY()
		USceneComponent* rootObj;

	UFUNCTION()
		virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	FPlayerEntered OnPlayerEntered;
	
};

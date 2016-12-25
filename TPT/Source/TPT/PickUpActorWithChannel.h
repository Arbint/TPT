// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickUpActorWithChannel.generated.h"

UCLASS()
class TPT_API APickUpActorWithChannel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpActorWithChannel();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
		USceneComponent* rootSceneComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
		USphereComponent* pickupTrigger;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
		UStaticMeshComponent* MeshGeo;
	
	
};

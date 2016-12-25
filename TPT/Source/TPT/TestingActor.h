// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TestingActor.generated.h"

class URandomMovmentComponent;

UCLASS()
class TPT_API ATestingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestingActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
		USceneComponent* RootComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
		UStaticMeshComponent* MeshGeo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "gaga")
		float lifeSpan;

	UPROPERTY()
		URandomMovmentComponent* RandomMovementComponent;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickupActor.generated.h"

DECLARE_DELEGATE(FPickedUpSignature)
DECLARE_DELEGATE_OneParam(FCustomDelegateSignature, float)

UCLASS()
class TPT_API APickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
		UStaticMeshComponent* VisualGeo;

	UPROPERTY()
		URotatingMovementComponent* RotatingComponent;

	FPickedUpSignature OnPickupDelegate;
	
};

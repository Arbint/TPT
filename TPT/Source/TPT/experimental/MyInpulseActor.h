// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyInpulseActor.generated.h"

UCLASS()
class TPT_API AMyInpulseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyInpulseActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "visual")
	USceneComponent* RootComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "visual")
	UStaticMeshComponent* MeshGeo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collison")
	USphereComponent* Trigger;

	UFUNCTION(BlueprintCallable, Category = "Collison")
	void Triggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "visual")
	float ImpulseStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "go")
	AActor* DudeToCollide;

public:
	virtual void Addinpulse(FVector Direction);
};

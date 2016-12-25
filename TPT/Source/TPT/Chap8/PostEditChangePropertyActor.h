// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Chap8/BasicDefinedStaticMeshActor.h"
#include "PostEditChangePropertyActor.generated.h"

/**
 * 
 */
UCLASS()
class TPT_API APostEditChangePropertyActor : public ABasicDefinedStaticMeshActor
{
	GENERATED_BODY()
	
	
	
public:
	APostEditChangePropertyActor();
	UPROPERTY(EditAnywhere)
		bool bShowStaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = test)
		UStaticMeshComponent* anotherMesh;

	UPROPERTY(EditAnywhere)
		FVector AnotherMeshRelativeLocation;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "OnConstructionActor.generated.h"

UCLASS()
class TPT_API AOnConstructionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOnConstructionActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	UPROPERTY()
		USceneComponent* RootComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = visual)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere)
		bool bShowStaticMesh;


	
	

	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PorpertySpecifiedActor.generated.h"

UCLASS()
class TPT_API APorpertySpecifiedActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APorpertySpecifiedActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditDefaultsOnly)
		bool bEditDefaultsOnly;
	UPROPERTY(EditInstanceOnly)
		bool bEditInstanceOnly;
	UPROPERTY(EditAnywhere)
		bool bEditAnywhere;
	UPROPERTY(VisibleDefaultsOnly)
		bool bVisibleDefaultsOnly;
	UPROPERTY(VisibleInstanceOnly)
		bool bVisibleInstanceOnly;
	UPROPERTY(VisibleAnywhere)
		bool bVisibleAnywhere;

	
};

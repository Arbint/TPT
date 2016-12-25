// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "Spotter.generated.h"

/**
 * 
 */
UCLASS()
class TPT_API ASpotter : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	ASpotter();
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintNativeEvent, Category = "HAHA")
	void OnPlayerSpotted(APawn* Player);
	
	
};

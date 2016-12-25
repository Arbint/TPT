// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "InventoryActor.generated.h"

class ATPTCharacter;
/**
 * 
 */
UCLASS()
class TPT_API AInventoryActor : public AStaticMeshActor
{
	GENERATED_BODY()
		AInventoryActor();
public:
	UFUNCTION()
	virtual void Pickup(ATPTCharacter* TheOnePickedMeUp);
	UFUNCTION()
	virtual void putDown(FTransform TargetLocation, FVector ThrowDirection);
	UFUNCTION()
		void AttachMeshToOwningPawn();
	UFUNCTION()
		void DetachMeshFromOwningPawn();

	UPROPERTY()
		ATPTCharacter* MyMaster;
	
};

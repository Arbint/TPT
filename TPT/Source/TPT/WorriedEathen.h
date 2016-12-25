// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Warrior.h"
#include "WorriedEathen.generated.h"

/**
 * 
 */
UCLASS()
class TPT_API AWorriedEathen : public AWarrior
{
	GENERATED_BODY()
		AWorriedEathen();
	virtual void Tick(float DeltaSeconds) override;
	virtual void updateMovement() override;
	UPROPERTY()
		UBoxComponent* TalkCollider;
	UFUNCTION()
		void OnTalkerOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
		virtual void TryInteract() override;
};

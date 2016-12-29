// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "CAIController.generated.h"

/**
 * 
 */
UCLASS()
class TPT_API ACAIController : public AAIController
{
	GENERATED_BODY()
public:
	ACAIController(const FObjectInitializer& ObjectInitializer);
	
protected:
	UPROPERTY(transient)
		UBlackboardComponent* BlackboardComp;
	UPROPERTY(transient)
		UBehaviorTreeComponent* BehaviorComp;

public:
	virtual void Possess(APawn* InPawn) override;

	uint8 EnemyKeyID;
	
};

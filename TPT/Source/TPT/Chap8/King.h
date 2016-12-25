// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "King.generated.h"

/**
 * 
 */
class AKing;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKingDeathSignature, AKing*, DeadKing);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnKingDeathSignatureNoDynamic, AKing*);

UCLASS()
class TPT_API AKing : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	AKing();
	UFUNCTION(BlueprintCallable, Category = King)
		void Die();

	UPROPERTY(BlueprintAssignable)
		FOnKingDeathSignature OnKingDeath;
	
	FOnKingDeathSignatureNoDynamic OnKingDeathNoDynamic;

	
};

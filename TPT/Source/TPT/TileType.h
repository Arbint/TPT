// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "TileType.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class TPT_API UTileType : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
		int32 MovementCost;
	UPROPERTY()
		bool CanBeBuiltOn;
	
	UPROPERTY()
		FString TileName;
};

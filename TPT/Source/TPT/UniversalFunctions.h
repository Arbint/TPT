// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "UniversalFunctions.generated.h"

/**
 * 
 */

UENUM()
enum EPlayerStatus
{
	Stopped UMETA(DisplayName = "Stopped"),
	Moving UMETA(DisplayName = "Moving"),
	Attacking UMETA(DisplayName = "Attacking"),
};

USTRUCT()
struct TPT_API FColorTexture
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		UTexture* Texture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		FLinearColor Color;
};

UCLASS(Blueprintable, BlueprintType)
class TPT_API UUniversalFunctions : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString FucName;
	
	UUniversalFunctions();

	UFUNCTION(BlueprintCallable, Category = "Info")
	static void PrintMsg(FString MessageToPrint = "Confirmed", FColor ColorOfTheText = FColor::Black);

	UFUNCTION(BlueprintCallable, Category = "Destory")
	void DestoryIt();

	void setName(FString NewName);
	
	UFUNCTION(BlueprintCallable, Category = "Info")
		static const FVector& GetDirectionToPlayer(FVector& FromPosition, FVector& Direction);
};

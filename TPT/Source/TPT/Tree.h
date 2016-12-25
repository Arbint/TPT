// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "Tree.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum TreeType
{
	Tree_Poplar,
	Tree_Spruce,
	Tree_Eucalyptus,
	Tree_RedWood
};
UCLASS()
class TPT_API ATree : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	ATree();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeType")
	TEnumAsByte<TreeType> Type;

public:
	UFUNCTION(BlueprintCallable, Category = "Fun")
		void SetType(TEnumAsByte<TreeType> TypeToAssign);
		
	
};

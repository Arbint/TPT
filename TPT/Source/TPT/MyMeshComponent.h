// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/MeshComponent.h"
#include "DynamicMeshBuilder.h"
#include "MyMeshComponent.generated.h"




/************************************************************************/
/*        UMyMeshComponent Class                   CHECKED              */
/************************************************************************/
UCLASS(ClassGroup = Experimental, meta = (BlueprintSpawnableComponent))
class TPT_API UMyMeshComponent : public UMeshComponent
{
	GENERATED_BODY()

public:
	TArray<int32> Indices;
	TArray<FVector> Vertices;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterial* TheMaterial;
	UMyMeshComponent();
};


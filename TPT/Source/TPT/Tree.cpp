// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "Tree.h"




ATree::ATree()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/Trees/Geometry/Meshes/Trees/Palm_Desktop.Palm_Desktop'"));
	if (MeshAsset.Succeeded())
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->bGenerateOverlapEvents = true;
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
}

void ATree::SetType(TEnumAsByte<TreeType> TypeToAssign)
{
	Type = TypeToAssign;
}

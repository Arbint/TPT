// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "UniversalFunctions.h"
#include "Door.h"




ADoor::ADoor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_GlassWindow.SM_GlassWindow'"));
	if (MeshAsset.Succeeded())
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
		GetStaticMeshComponent()->bGenerateOverlapEvents = true;
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	SetActorEnableCollision(true);
}

bool ADoor::CanInteract_Implementation()
{
	return IIFInterable::CanInteract_Implementation();
}

void ADoor::PerformInteract_Implementation()
{
	UUniversalFunctions::PrintMsg("The door refuse to budge. perhaps there is a hidden switch nearby?");
}

void ADoor::Open_Implementation()
{
	AddActorLocalOffset(FVector(0.0f, 0.0f, 200.0f));
}

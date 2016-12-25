// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "Interactable/Openable.h"
#include "DoolBell.h"




ADoolBell::ADoolBell()
{
	bHasBeenPushed = false;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_GlassWindow.SM_GlassWindow'"));
	if (MeshAsset.Succeeded())
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
		GetStaticMeshComponent()->bGenerateOverlapEvents = true;
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetWorldScale3D(FVector(0.5, 0.5, 0.5));
	SetActorEnableCollision(true);
	
	DoorToOpen = nullptr;
}

bool ADoolBell::CanInteract_Implementation()
{
	return !bHasBeenPushed;
}

void ADoolBell::PerformInteract_Implementation()
{
	bHasBeenPushed = true;
	if (DoorToOpen->GetClass()->ImplementsInterface(UOpenable::StaticClass()))
	{
		IOpenable::Execute_Open(DoorToOpen);
	}
}

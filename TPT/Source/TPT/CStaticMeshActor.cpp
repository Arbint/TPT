// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "UniversalFunctions.h"
#include "CStaticMeshActor.h"

ACStaticMeshActor::ACStaticMeshActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshToUse(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Statue.SM_Statue'"));
	if (MeshToUse.Succeeded())
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshToUse.Object);
		//GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
		GetStaticMeshComponent()->bGenerateOverlapEvents = true;
		GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	}
	SetActorEnableCollision(true);
}

void ACStaticMeshActor::StartTalking_Implementation()
{
	UUniversalFunctions::PrintMsg("i have no idea");
	ITalker::StartTalking_Implementation();
}

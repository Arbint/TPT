// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "King.h"




AKing::AKing()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Bush.SM_Bush'"));
	if (MeshAsset.Succeeded())
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->bGenerateOverlapEvents = true;
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
}

void AKing::Die()
{

	//OnKingDeath.Broadcast(this);
	OnKingDeathNoDynamic.Broadcast(this);
	ConditionalBeginDestroy();
}

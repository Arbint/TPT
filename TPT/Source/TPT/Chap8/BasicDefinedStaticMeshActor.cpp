// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "BasicDefinedStaticMeshActor.h"




ABasicDefinedStaticMeshActor::ABasicDefinedStaticMeshActor()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->bGenerateOverlapEvents = true;
}

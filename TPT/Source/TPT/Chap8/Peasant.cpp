// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "UniversalFunctions.h"
#include "Peasant.h"




APeasant::APeasant()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Rock.SM_Rock'"));
	if (MeshAsset.Succeeded())
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->bGenerateOverlapEvents = true;
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
}

void APeasant::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> Kings;
	UGameplayStatics::GetAllActorsOfClass(this, AKing::StaticClass(), Kings);
	if (Kings.Num() > 0)
	{
		UUniversalFunctions::PrintMsg("Got the kings");
		AKing* theKing = (AKing*)Kings[0];
		if (theKing != nullptr)
		{
			UUniversalFunctions::PrintMsg("I am the king!!");
			theKing->OnKingDeathNoDynamic.AddUObject(this, &APeasant::Flee);
		}
	}
}

void APeasant::Flee(AKing* DeadKing)
{
	if (DeadKing != nullptr)
	{
		UUniversalFunctions::PrintMsg("Waily Waily!");
		FVector FleeVector = GetActorLocation() - DeadKing->GetActorLocation();
		FleeVector.Normalize();
		FleeVector *= 500.0f;
		SetActorLocation(GetActorLocation() + FleeVector);
	}
}

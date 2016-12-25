// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "Spotter.h"



ASpotter::ASpotter()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Lamp_Wall.SM_Lamp_Wall'"));
	if (MeshAsset.Succeeded())
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->bGenerateOverlapEvents = false;
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetRelativeRotation(FRotator(90.0f, 0, 0));
}

void ASpotter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//FVector EndLocation = GetActorLocation() + ActorToWorld().TransformVector(FVector(0.0f, 0.0f, 200.0f));
	FVector EndLocation = ActorToWorld().GetLocation() + ActorToWorld().TransformVector(FVector(0.0f, 0.0f, 200.0f));
	FHitResult HitResult;
	if (GetWorld()->SweepSingleByChannel(HitResult,
		GetActorLocation(),
		EndLocation,
		FQuat::Identity,
		ECC_Pawn,
		FCollisionShape::MakeSphere(25),
		FCollisionQueryParams("Spot",
			true,
			this
		)))
	{
		APawn* SpottedPlayer = Cast<APawn>(HitResult.Actor.Get());
		if (SpottedPlayer != nullptr)
		{
			OnPlayerSpotted(SpottedPlayer);
		}	
	}
	DrawDebugLine(GetWorld(), GetActorLocation(), EndLocation, FColor::Red);
}

void ASpotter::OnPlayerSpotted_Implementation(APawn* Player)
{
	
}


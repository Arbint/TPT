// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "TPTCharacter.h"
#include "InventoryActor.h"

AInventoryActor::AInventoryActor()
	:Super()
{
	PrimaryActorTick.bCanEverTick = true;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/ThirdPersonCPP/Axe/Axe_Low.Axe_Low'"));
	if (MeshAsset.Succeeded())
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	SetActorEnableCollision(true);
}

void AInventoryActor::Pickup(ATPTCharacter* TheOnePickedMeUp)
{
	SetActorTickEnabled(false);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(false);
	UStaticMeshComponent* meshComp = GetStaticMeshComponent();
	if (meshComp)
	{
		meshComp->SetSimulatePhysics(false);
	}
	MyMaster = TheOnePickedMeUp;
	SetOwner(TheOnePickedMeUp);
	AttachMeshToOwningPawn();
}

void AInventoryActor::putDown(FTransform TargetLocation, FVector ThrowDirection)
{
	SetActorTickEnabled(true);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorLocation(TargetLocation.GetLocation());
	UStaticMeshComponent* meshComp = GetStaticMeshComponent();
	if (meshComp)
	{
		meshComp->SetSimulatePhysics(true);
		meshComp->AddImpulse(ThrowDirection * 100.f);
		meshComp->AddTorque(FVector(1, 1, 1 * 4000000));
	}
	DetachMeshFromOwningPawn();
}

void AInventoryActor::AttachMeshToOwningPawn()
{
	if (MyMaster)
	{
		USkeletalMeshComponent* MaterSkeletalBoy = MyMaster->GetMesh();
		GetStaticMeshComponent()->AttachToComponent(MaterSkeletalBoy, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "AxeHandle");
	}
}

void AInventoryActor::DetachMeshFromOwningPawn()
{
	if (MyMaster)
	{
		GetStaticMeshComponent()->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
	}
}

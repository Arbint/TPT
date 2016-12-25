// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "SlidingDoor.h"


// Sets default values
ASlidingDoor::ASlidingDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Mesh Component");
	RootComp = CreateDefaultSubobject<USceneComponent>("Root Comp");
	SetRootComponent(RootComp);
	MeshComp->SetupAttachment(RootComp);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Door.SM_Door'"));
	if (MeshAsset.Succeeded())
	{
		MeshComp->SetStaticMesh(MeshAsset.Object);
		MeshComp->bGenerateOverlapEvents = true;
	}
	MeshComp->SetMobility(EComponentMobility::Movable);
	SetActorEnableCollision(true);
	IsOpen = false;
}

// Called when the game starts or when spawned
void ASlidingDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASlidingDoor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (IsOpen)
	{
		SetActorLocation(FMath::Lerp(GetActorLocation(), TargetLocation, DeltaTime ));
	}
}

void ASlidingDoor::Open()
{
	TargetLocation = ActorToWorld().TransformPositionNoScale(FVector(0.0f, 0.0f, 200.0f));
	IsOpen = true;
}


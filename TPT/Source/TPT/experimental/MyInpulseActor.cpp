// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "MyInpulseActor.h"
#include "WorriedEathen.h"
#include "UniversalFunctions.h"


// Sets default values
AMyInpulseActor::AMyInpulseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	MeshGeo = CreateDefaultSubobject<UStaticMeshComponent>("MeshGeo");
	Trigger = CreateDefaultSubobject<USphereComponent>("Trigger");

	SetRootComponent(RootComp);
	MeshGeo->SetupAttachment(RootComp);
	Trigger->SetupAttachment(RootComp);
	MeshGeo->SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void AMyInpulseActor::BeginPlay()
{
	Super::BeginPlay();
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AMyInpulseActor::Triggered);
}

// Called every frame
void AMyInpulseActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AMyInpulseActor::Triggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AWorriedEathen* player = (AWorriedEathen*)OtherActor;
	if (player != nullptr)
	{
		if (DudeToCollide != nullptr)
		{

			Addinpulse(DudeToCollide->GetActorLocation() - GetActorLocation());
		}
	}
}

void AMyInpulseActor::Addinpulse(FVector Direction)
{
	Direction.Normalize();
	MeshGeo->SetSimulatePhysics(true);
	MeshGeo->AddImpulse(Direction * ImpulseStrength);

}


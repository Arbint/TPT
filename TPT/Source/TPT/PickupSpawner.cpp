// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "PickupActor.h"
#include "PickupSpawner.h"


// Sets default values
APickupSpawner::APickupSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnLocation = CreateDefaultSubobject<USceneComponent>("SpanwLocation");

}

// Called when the game starts or when spawned
void APickupSpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnPickup();
}

// Called every frame
void APickupSpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void APickupSpawner::PickupCollected()
{
	UWorld* theWorld = GetWorld();
	if (theWorld)
	{
		theWorld->GetTimerManager().SetTimer(MyTimer, this, &APickupSpawner::SpawnPickup, 10, false);
		CurrentPickup->OnPickupDelegate.Unbind();
		CurrentPickup->Destroy();
	}
}

void APickupSpawner::SpawnPickup()
{
	UWorld* theWorld = GetWorld();
	if (theWorld)
	{
		CurrentPickup = theWorld->SpawnActor<APickupActor>(CurrentPickupClass, GetTransform());
		CurrentPickup->VisualGeo->SetMaterial(0, Material);
		CurrentPickup->OnPickupDelegate.BindUObject(this, &APickupSpawner::PickupCollected);
	}
}


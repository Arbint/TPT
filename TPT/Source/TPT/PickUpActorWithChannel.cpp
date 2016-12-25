// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "PickUpActorWithChannel.h"


// Sets default values
APickUpActorWithChannel::APickUpActorWithChannel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	rootSceneComp = CreateDefaultSubobject<USceneComponent>("RootComponent");
	SetRootComponent(rootSceneComp);
	pickupTrigger = CreateDefaultSubobject<USphereComponent>("PickupTrigger");
	MeshGeo = CreateDefaultSubobject<UStaticMeshComponent>("MeshGeo");
	pickupTrigger->SetupAttachment(rootSceneComp);
	MeshGeo->SetupAttachment(rootSceneComp);
	MeshGeo->SetCollisionProfileName("IgnoreAll");
}

// Called when the game starts or when spawned
void APickUpActorWithChannel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUpActorWithChannel::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


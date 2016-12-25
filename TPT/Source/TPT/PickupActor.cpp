// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "MyGameMode.h"
#include "PickupActor.h"


// Sets default values
APickupActor::APickupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VisualGeo = CreateDefaultSubobject<UStaticMeshComponent>("Visual Geometry");
	RotatingComponent = CreateDefaultSubobject<URotatingMovementComponent>("Rotating Component");
	SetRootComponent(VisualGeo);

	VisualGeo->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RotatingComponent->RotationRate = FRotator(10, 0, 10);
}

// Called when the game starts or when spawned
void APickupActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void APickupActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	OnPickupDelegate.ExecuteIfBound();
	AMyGameMode* currentGameMode = (AMyGameMode*)GetWorld()->GetAuthGameMode();
}


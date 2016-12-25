// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "RandomMovmentComponent.h"
#include "TestingActor.h"


// Sets default values
ATestingActor::ATestingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(RootComp);
	MeshGeo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Geometry"));
	MeshGeo->SetupAttachment(RootComponent);

	RandomMovementComponent = CreateDefaultSubobject<URandomMovmentComponent>(TEXT("MovementComponent"));

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Lamp_Ceiling.SM_Lamp_Ceiling'"));
	if (MeshAsset.Succeeded())
	{
		MeshGeo->SetStaticMesh(MeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void ATestingActor::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(lifeSpan);
}

// Called every frame
void ATestingActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


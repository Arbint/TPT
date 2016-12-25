// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"

#include "UniversalFunctions.h"
#include "OnConstructionActor.h"


// Sets default values
AOnConstructionActor::AOnConstructionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	SetRootComponent(RootComp);
	MeshComp->SetupAttachment(RootComp);
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Props/SM_WindowFrame.SM_WindowFrame'"));
	if (MeshAsset.Succeeded())
	{
		MeshComp->SetStaticMesh(MeshAsset.Object);
		MeshComp->bGenerateOverlapEvents = true;
	
	}
	MeshComp->SetMobility(EComponentMobility::Movable);
	bShowStaticMesh = true;
	bReplicates = true;
}

// Called when the game starts or when spawned
void AOnConstructionActor::BeginPlay()
{
	Super::BeginPlay();
	if (Role = ROLE_Authority)
	{
		UUniversalFunctions::PrintMsg("I am the server");
	}
}

// Called every frame
void AOnConstructionActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


void AOnConstructionActor::OnConstruction(const FTransform& Transform)
{
	MeshComp->SetVisibility(bShowStaticMesh);
}

void AOnConstructionActor::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other,OtherComp,bSelfMoved,HitLocation,HitNormal,NormalImpulse,Hit);
	UUniversalFunctions::PrintMsg("GOT HIT");
	bShowStaticMesh = !bShowStaticMesh;
}



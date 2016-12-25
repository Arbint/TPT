// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "GravityObject.h"
#include "AntiGravityVolume.h"


// Sets default values
AAntiGravityVolume::AAntiGravityVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>("CollisionBox");
}

// Called when the game starts or when spawned
void AAntiGravityVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAntiGravityVolume::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AAntiGravityVolume::NotifyActorBeginOverlap(AActor* OtherActor)
{
	IGravityObject* ActorToChange = Cast<IGravityObject>(OtherActor);
	if (ActorToChange != nullptr)
	{
		ActorToChange->DisableGravity();
		UPrimitiveComponent* rootOfActor = (UPrimitiveComponent*)OtherActor->GetRootComponent();
		if (rootOfActor)
		{
			rootOfActor->AddImpulse(FVector(0.0f, 100000.0f, 0.0f));
		}
		
	}
}

void AAntiGravityVolume::NotifyActorEndOverlap(AActor* OtherActor)
{
	IGravityObject* ActorToChange = Cast<IGravityObject>(OtherActor);
	if (ActorToChange != nullptr)
	{
		ActorToChange->EnableGravity();
	}
}


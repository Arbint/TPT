// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "MyGameMode.h"
#include "TriggerActor.h"


// Sets default values
ATriggerActor::ATriggerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	rootObj = CreateDefaultSubobject<USceneComponent>(TEXT("TransformationRoot"));
	SetRootComponent(rootObj);
	SphereTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger"));
	SphereTrigger->SetupAttachment(rootObj);
}

// Called when the game starts or when spawned
void ATriggerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATriggerActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATriggerActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr)
	{
		AMyGameMode* currentGameMode = (AMyGameMode*)GetWorld()->GetAuthGameMode();
		if (currentGameMode != nullptr)
		{
			currentGameMode->MyStandardDelegate.ExecuteIfBound();
			currentGameMode->MyOneParmDelegate.ExecuteIfBound(FLinearColor(1,1, 0, 1));
			currentGameMode->MyMulticastDelegate.Broadcast();
			OnPlayerEntered.Broadcast();
		}
	}

}


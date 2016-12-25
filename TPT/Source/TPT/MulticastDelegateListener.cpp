// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "MyGameMode.h"
#include "MulticastDelegateListener.h"


// Sets default values
AMulticastDelegateListener::AMulticastDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	SetRootComponent(PointLight);
}

// Called when the game starts or when spawned
void AMulticastDelegateListener::BeginPlay()
{
	PointLight->SetVisibility(false);
	Super::BeginPlay();
	UWorld* TheWorld = GetWorld();
	if (TheWorld)
	{
		AMyGameMode* CurrentGameMode = (AMyGameMode*)TheWorld->GetAuthGameMode();
		if (CurrentGameMode != nullptr)
		{
			MydelegateHandle = CurrentGameMode->MyMulticastDelegate.AddUObject(this, &AMulticastDelegateListener::ToggleLight);
		}
	}
}

// Called every frame
void AMulticastDelegateListener::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AMulticastDelegateListener::ToggleLight()
{
	PointLight->ToggleVisibility();
}

void AMulticastDelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UWorld* TheWorld = GetWorld();
	if (TheWorld)
	{
		AMyGameMode* CurrentGameMode = (AMyGameMode*)TheWorld->GetAuthGameMode();
		if (CurrentGameMode != nullptr)
		{
			CurrentGameMode->MyMulticastDelegate.Remove(MydelegateHandle);
		}
	}

}


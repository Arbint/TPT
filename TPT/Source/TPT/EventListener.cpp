// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "TriggerActor.h"
#include "EventListener.h"

// Sets default values
AEventListener::AEventListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointLight = CreateDefaultSubobject<UPointLightComponent>("Point Light");
	SetRootComponent(PointLight);
}

// Called when the game starts or when spawned
void AEventListener::BeginPlay()
{
	Super::BeginPlay();
	if (TriggerEventSource != nullptr)
	{
		TriggerEventSource->OnPlayerEntered.AddUObject(this, &AEventListener::OnTriggerEvent);
	}
}

// Called every frame
void AEventListener::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AEventListener::OnTriggerEvent()
{
	PointLight->SetLightColor(FLinearColor(0,1,0,1));
}


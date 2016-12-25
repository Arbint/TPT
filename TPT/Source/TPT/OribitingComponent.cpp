// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "OribitingComponent.h"


// Sets default values for this component's properties
UOribitingComponent::UOribitingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	RotationSpeed = 5;
	OrbitDistance = 100;
	CurrentValue = 0;
	RotateToFaceOutWards = true;
	// ...
}


// Called when the game starts
void UOribitingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOribitingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpDateOribit(DeltaTime);
	// ...
}

void UOribitingComponent::UpDateOribit(float DeltaTime)
{
	float CurrentValueInRadius = FMath::DegreesToRadians<float>(CurrentValue);
	SetRelativeLocation(FVector(OrbitDistance * FMath::Cos(CurrentValueInRadius), OrbitDistance * FMath::Sin(CurrentValueInRadius), RelativeLocation.Z));
	if (RotateToFaceOutWards)
	{
		FVector LookDir = RelativeLocation.GetSafeNormal();
		FRotator LookAtRot = LookDir.Rotation();
		SetRelativeRotation(LookAtRot);
	}
	CurrentValue = FMath::Fmod(CurrentValue + (RotationSpeed * DeltaTime), 360);
}

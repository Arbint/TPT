// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "PorpertySpecifiedActor.h"


// Sets default values
APorpertySpecifiedActor::APorpertySpecifiedActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APorpertySpecifiedActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APorpertySpecifiedActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


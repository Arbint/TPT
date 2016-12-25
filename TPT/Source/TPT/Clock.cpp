// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "TimeOfTheDayHandler.h"
#include "Clock.h"


// Sets default values
AClock::AClock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>("Root Transform");
	SetRootComponent(RootSceneComponent);
	HourHandle = CreateDefaultSubobject<USceneComponent>("Hour rotation Pivot");
	MinuteHandle = CreateDefaultSubobject<USceneComponent>("Minute rotation Pivot");
	HourHand = CreateDefaultSubobject<UStaticMeshComponent>("Hour Pointer Geo");
	MinuteHand = CreateDefaultSubobject<UStaticMeshComponent>("Minute Pointer Geo");
	ClockFace = CreateDefaultSubobject<UStaticMeshComponent>("Clock Face");

	HourHandle->SetupAttachment(RootSceneComponent);
	MinuteHandle->SetupAttachment(RootSceneComponent);
	ClockFace->SetupAttachment(RootSceneComponent);

	HourHand->SetupAttachment(HourHandle);
	MinuteHand->SetupAttachment(MinuteHandle);
}

// Called when the game starts or when spawned
void AClock::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> TimeOfDayHandlers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATimeOfTheDayHandler::StaticClass(), TimeOfDayHandlers);
	if (TimeOfDayHandlers.Num() != 0)
	{
		ATimeOfTheDayHandler* TimeOfDayHandler = Cast<ATimeOfTheDayHandler>(TimeOfDayHandlers[0]);
		MyDelegateHandle = TimeOfDayHandler->OnTimeChanged.AddUObject(this, &AClock::TimeChanged);
	}
}

// Called every frame
void AClock::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AClock::TimeChanged(int32 Hours, int32 Minutes)
{
	HourHandle->SetRelativeRotation(FRotator(0,30 * Hours, 0));
	MinuteHandle->SetRelativeRotation(FRotator(0,6 * Minutes, 0));
}


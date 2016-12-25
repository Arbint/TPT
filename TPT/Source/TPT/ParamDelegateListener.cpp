// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "MyGameMode.h"
#include "ParamDelegateListener.h"


// Sets default values
AParamDelegateListener::AParamDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointLight = CreateDefaultSubobject<UPointLightComponent>("Visual");
	DisabledPointLight = CreateDefaultSubobject<UPointLightComponent>("Visual_2");
	SetRootComponent(PointLight);
	DisabledPointLight->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AParamDelegateListener::BeginPlay()
{
	DisabledPointLight->SetActive(false);
	Super::BeginPlay();
	if (GetWorld())
	{
		AMyGameMode* CurrentGameMode = (AMyGameMode*)GetWorld()->GetAuthGameMode();
		if (CurrentGameMode)
		{
			CurrentGameMode->MyOneParmDelegate.BindUObject(this, &AParamDelegateListener::SetLightColor, true);
		}
	}

}

// Called every frame
void AParamDelegateListener::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AParamDelegateListener::SetLightColor(FLinearColor LightColor, bool EnableLight)
{
	PointLight->SetLightColor(LightColor);
	DisabledPointLight->SetActive(EnableLight);
	DisabledPointLight->SetRelativeLocation(FVector(0.0f, 0.0f, 300.0f));
	DisabledPointLight->SetLightColor(FLinearColor(1,0,0,1));
}

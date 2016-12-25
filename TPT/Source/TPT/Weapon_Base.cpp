// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "UniversalFunctions.h"
#include "Weapon_Base.h"


// Sets default values
AWeapon_Base::AWeapon_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(RootComp);
	WeaponGeo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Mesh"));
	WeaponGeo->SetupAttachment(RootComponent);
	Adam = NewObject<UUniversalFunctions>(GetTransientPackage(), UUniversalFunctions::StaticClass());
	if (Adam)
	{
		UUniversalFunctions::PrintMsg("Adam is alive");
	}
	InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("inputComponent"));

}

// Called when the game starts or when spawned
void AWeapon_Base::BeginPlay()
{
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	InputComponent->BindAction("CheckAdam", IE_Pressed, this, &AWeapon_Base::CheckAdam);
	UUniversalFunctions::PrintMsg("Check Adam");
	if (Adam)
	{
		UUniversalFunctions::PrintMsg("Adam is alive");
	}
	Super::BeginPlay();
}

// Called every frame
void AWeapon_Base::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AWeapon_Base::CheckAdam()
{
	if (Adam)
	{
		UUniversalFunctions::PrintMsg("Adam is Alive");
	}
	else
	{
		UUniversalFunctions::PrintMsg("Adam is Dead");
	}
	
}


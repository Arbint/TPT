// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "UniversalFunctions.h"
#include "C_PlayerController.h"
#include "Warrior.h"


// Sets default values
AWarrior::AWarrior()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	ViewCamera = CreateDefaultSubobject<UCameraComponent>("View Camera");
	CameraBoom->SetupAttachment(RootComponent);
	ViewCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraBoom->TargetArmLength = 600.0f;
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AWarrior::CollideWithItem);
}
// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWarrior::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	updateMovement();
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
}

void AWarrior::updateMovement()
{
	AC_PlayerController* currentController = (AC_PlayerController*)GetController();
	if (currentController)
	{
		FVector2D &LastInput = currentController->LastMovementInput;
		AddMovementInput(GetActorForwardVector(), LastInput.X);
		AddMovementInput(GetActorRightVector(), LastInput.Y);
		LastInput = FVector2D(0.f, 0.f);
	}
	
}

void AWarrior::CollideWithItem(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	UUniversalFunctions::PrintMsg("Alright, I got it, I got it");
}

void AWarrior::TryInteract()
{
	
}

void AWarrior::GetDirectionToPlayer(FVector& FromPosition, FVector& OutDirection) const
{
	OutDirection = GetActorLocation() - FromPosition;
	OutDirection.Normalize();
}



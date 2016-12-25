// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Warrior.generated.h"

UCLASS()
class TPT_API AWarrior : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarrior();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Camera component
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Viewing")
	UCameraComponent* ViewCamera;
	USpringArmComponent* CameraBoom;

	virtual void updateMovement();
	
	UFUNCTION()
	void CollideWithItem(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	
	UFUNCTION()
	virtual void TryInteract();
	
	UFUNCTION()
	virtual void GetDirectionToPlayer(FVector& FromPosition, FVector& OutDirection) const;
};

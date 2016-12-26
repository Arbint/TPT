// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "C_PlayerController.generated.h"

class AWarrior;
/**
 * 
 */
UCLASS()
class TPT_API AC_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AC_PlayerController();

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Switch")
	TArray<TSubclassOf<ACharacter>> warriorTemplates;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Switch")
	TSubclassOf<ACharacter> DefaultWorrior;

	UPROPERTY()
		ACharacter* PossessedWorrior;
	int currentWorrierIndex;

	UPROPERTY()
		FVector2D LastMovementInput = FVector2D(0.f,0.f);
	UPROPERTY()
		FVector2D LastRoataionInput = FVector2D(0.f, 0.f);
	UFUNCTION()
	virtual void SetupInputComponent() override;
	UFUNCTION()
		void MoveForward(float moveAmount);
	UFUNCTION()
		void MoveRight(float moveAmount);
	UFUNCTION()
		void RotateYaw(float rotateAmount);
	UFUNCTION()
		void RotatePitch(float rotateAmount);
	UFUNCTION()
		void Jump();
	UFUNCTION()
		void Sprint();
	UFUNCTION()
		void Interact();
	UFUNCTION()
		void Down(float DownAmount);
	UFUNCTION(BlueprintCallable, Category = "In Game Mechanic")
	void ChangeCharacter();
	UFUNCTION()
	ACharacter* SpawnWarrior(TSubclassOf<ACharacter> Template);
	UFUNCTION()
	void NormalizeInput();
	UFUNCTION()
		bool IsPlayerMoved();
	UFUNCTION()
		bool IsPlayerRotated();

	//C++ Code based keyMapping:
	FInputAxisKeyMapping DownKey = FInputAxisKeyMapping("Down", EKeys::C, 1.0f);
	FInputActionKeyMapping SprintKey = FInputActionKeyMapping("Sprint", EKeys::LeftShift, 0, 0, 0, 0);


	UFUNCTION()
		void createButton();
};



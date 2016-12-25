// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "UniversalFunctions.h"
#include "TPTCharacter.generated.h"

class AWeapon_Base;
class NoneNativeClass;
class UInventoryComponent;
class AInventoryActor;
class MyClass
{

};

class USpawnerComponent;

UCLASS(config=Game)
class ATPTCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	ATPTCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
		TSubclassOf<AWeapon_Base> UClassOfAxe;

	UPROPERTY(EditAnywhere, meta = (MetaClass = "TPTGameMode"), Category = "Unit")
		FStringClassReference UclassGameMode;

	UFUNCTION(BlueprintCallable, Category = "Instantiate")
		AWeapon_Base* CreateWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		TArray<AWeapon_Base*> weaponInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		TArray<UUniversalFunctions*> UnversalObjects;

	UFUNCTION(BlueprintCallable, Category = "Instantiate")
		void DeleteWeapon();

	UFUNCTION(BlueprintCallable, Category = "Instantiate")
		void DeleteUnvFuc();
	UFUNCTION(BlueprintCallable, Category = "Instantiate")
		void CreateAxeOnMe(float height);

	UFUNCTION(BlueprintCallable, Category = "Instantiate")
		void CreateUnversalFunction();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extra")
		FColorTexture ColorTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extra")
		TEnumAsByte<EPlayerStatus> playerStatue;

	UFUNCTION(BlueprintCallable, Category = "Try")
	void TrySmartPtrWithClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		USpawnerComponent* TheSpawnerComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		UInventoryComponent* MyInventory;
	
	UFUNCTION()
		void DropItem();
	UFUNCTION()
		void TakeItem(AInventoryActor* InventoryItem);
	
	//Notify hit
	UFUNCTION()
		virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComponent, bool bSelfMoved, FVector HitLocaiton, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintCallable, Category = "Info")
		void PrintName() const;
};


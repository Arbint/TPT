// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Weapon_Base.generated.h"

class UUniversalFunctions;

UCLASS()
class TPT_API AWeapon_Base : public AActor
{
	GENERATED_BODY()

	
		
public:	
	// Sets default values for this actor's properties
	AWeapon_Base();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	UPROPERTY()
		USceneComponent* RootComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	UStaticMeshComponent* WeaponGeo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	UDamageType* DamageType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SmartPtrTest")
	UUniversalFunctions* Adam; 

	UFUNCTION(BlueprintCallable, Category = "SmartPtrTest")
	void CheckAdam();
};

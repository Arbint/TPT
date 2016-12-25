// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "OribitingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TPT_API UOribitingComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOribitingComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
		bool RotateToFaceOutWards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
		float RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
		float OrbitDistance;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Rotation")
		float CurrentValue;
	
	UFUNCTION()
		void UpDateOribit(float DeltaTime);

};

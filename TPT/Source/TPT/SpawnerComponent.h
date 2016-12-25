// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "SpawnerComponent.generated.h"

class ATestingActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TPT_API USpawnerComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnerComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<ATestingActor> actorToSpawn;
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void Spawn();
};

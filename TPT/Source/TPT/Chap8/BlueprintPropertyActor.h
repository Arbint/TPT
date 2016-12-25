// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BlueprintPropertyActor.generated.h"

UCLASS()
class TPT_API ABlueprintPropertyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlueprintPropertyActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	UPROPERTY(BlueprintReadWrite, Category = "CookBook")
		bool bReadWriteProperty;
	UPROPERTY(BlueprintReadOnly, Category = "CookBook")
		bool bReadOnlyProperty;
};

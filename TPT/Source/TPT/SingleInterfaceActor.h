// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TestInterface.h"
#include "SingleInterfaceActor.generated.h"

UCLASS()
class TPT_API ASingleInterfaceActor : public AActor, public ITestInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASingleInterfaceActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MyCategory")
		bool ReactToHighMoon();
	virtual bool ReactToHighMoon_Implementation() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "MyCategory")
		bool ReactToMidnight();
		bool ReactToMidnight_Implementation();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "Interactable/IFInteractable.h"
#include "DoolBell.generated.h"

/**
 * 
 */
UCLASS()
class TPT_API ADoolBell : public AStaticMeshActor, public IIFInterable
{
	GENERATED_BODY()
	
public:
	ADoolBell();
	virtual bool CanInteract_Implementation() override;
	virtual void PerformInteract_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door To Open")
		AActor* DoorToOpen;
private:
	bool bHasBeenPushed;
};

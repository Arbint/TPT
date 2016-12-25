// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "Interactable/Openable.h"
#include "Interactable/IFInteractable.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class TPT_API ADoor : public AStaticMeshActor, public IOpenable, public IIFInterable
{
	GENERATED_BODY()
public:
	ADoor();
	UFUNCTION()
	virtual bool CanInteract_Implementation() override;

	UFUNCTION()
	virtual void PerformInteract_Implementation() override;

	UFUNCTION()
	virtual void Open_Implementation() override;
};

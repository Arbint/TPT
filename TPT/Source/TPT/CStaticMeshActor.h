// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "Interfaces/Talker.h"
#include "CStaticMeshActor.generated.h"

/**
 * 
 */
UCLASS()
class TPT_API ACStaticMeshActor : public AStaticMeshActor, public ITalker
{
	GENERATED_BODY()
public:
	ACStaticMeshActor();

	virtual void StartTalking_Implementation() override;
};

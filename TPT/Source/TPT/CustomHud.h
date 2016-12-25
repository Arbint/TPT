// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "CustomHud.generated.h"

/**
 * 
 */
UCLASS()
class TPT_API ACustomHud : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void DrawHUD() override;
	
	
};

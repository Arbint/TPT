// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "CustomHud.h"



void ACustomHud::DrawHUD()
{
	Super::DrawHUD();
	if (GEngine)
	{
		Canvas->DrawText(GEngine->GetSmallFont(), TEXT("test string to be printed to screen"), 10, 10);
		FCanvasBoxItem ProgressBar(FVector2D(5, 25), FVector2D(200, 5));
		Canvas->DrawItem(ProgressBar);
		DrawRect(FLinearColor::Red, 5, 25, 100, 5);

	}
}

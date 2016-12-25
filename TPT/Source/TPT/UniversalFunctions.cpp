// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "UniversalFunctions.h"




UUniversalFunctions::UUniversalFunctions()
{
	FucName = TEXT("Adam");
	PrintMsg(FucName + " Got Created");
}

void UUniversalFunctions::PrintMsg(FString MessageToPrint, FColor ColorOfTheText)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, MessageToPrint);
	}
}

void UUniversalFunctions::DestoryIt()
{
	PrintMsg("Ok, I am dying" + FucName);
	ConditionalBeginDestroy();
}

void UUniversalFunctions::setName(FString NewName)
{
	FucName = NewName;
}

const FVector& UUniversalFunctions::GetDirectionToPlayer(FVector& FromPosition, FVector& Direction)
{
	Direction = FVector::ZeroVector;
	return Direction;
}


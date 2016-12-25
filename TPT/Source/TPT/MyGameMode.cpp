// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "UniversalFunctions.h"
#include "Warrior.h"
#include "Weapon_Base.h"
#include "SingleInterfaceActor.h"
#include "CustomHud.h"
#include "MyGameMode.h"
#include "C_PlayerController.h"



AMyGameMode::AMyGameMode()
{
	//HUDClass = ACustomHud::StaticClass();
	PlayerControllerClass = AC_PlayerController::StaticClass();
}

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();
	FindActorsUsingInerface();
}

void AMyGameMode::FindActorsUsingInerface()
{
	for (TActorIterator<AActor> It(GetWorld(), AActor::StaticClass()); It; ++It)
	{
		AActor* Actor = *It;
		ITestInterface* MyInterfaceInstance = Cast<ITestInterface>(Actor);
		if (MyInterfaceInstance)
		{
			UUniversalFunctions::PrintMsg(FString::Printf(TEXT("%s is the actor"), *(Actor->GetName())));

			MyInterfaceInstances.Add(Actor);
		}
	}
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, FString::Printf(TEXT("%d actors implement thie interface"), MyInterfaceInstances.Num()));
	}

}



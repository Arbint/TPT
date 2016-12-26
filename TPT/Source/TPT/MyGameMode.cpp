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
	Widget = SNew(SVerticalBox) + SVerticalBox::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)
	[
		SNew(SButton).Content()
		[
			SNew(STextBlock).Text(FText::FromString(TEXT("Test Button")))
		]
	];
	GEngine->GameViewport->AddViewportWidgetForPlayer(GetWorld()->GetFirstLocalPlayerFromController(), Widget.ToSharedRef(), 1);
	GetWorld()->GetTimerManager().SetTimer(HUDToggleTimer, FTimerDelegate::CreateLambda
	([this] 
	{
		if (this->Widget->GetVisibility().IsVisible())
		{
			this->Widget->SetVisibility(EVisibility::Hidden);
		}
		else
		{
			this->Widget->SetVisibility(EVisibility::Visible);
		}
	})
	, 5, true);
}

void AMyGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(HUDToggleTimer);
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



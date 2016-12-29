// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "Warrior.h"
#include "PickupActor.h"
#include "UniversalFunctions.h"
#include "C_PlayerController.h"
#include "SlateBasics.h"
#include "SButton.h"
#include "STextBlock.h"



AC_PlayerController::AC_PlayerController()
{

}

void AC_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	PossessedWorrior = SpawnWarrior(DefaultWorrior);
	Possess(PossessedWorrior);

	

}

void AC_PlayerController::Tick(float DeltaSeconds)
{
	NormalizeInput();
}

void AC_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		PlayerInput->AddAxisMapping(DownKey);
		PlayerInput->AddActionMapping(SprintKey);
		InputComponent->BindAxis("MoveForward", this, &AC_PlayerController::MoveForward);
		InputComponent->BindAxis("MoveRight", this, &AC_PlayerController::MoveRight);
		InputComponent->BindAction("ChangeCharacter", IE_Pressed, this, &AC_PlayerController::ChangeCharacter); 
		InputComponent->BindAxis("Turn", this, &AC_PlayerController::RotateYaw);
		InputComponent->BindAxis("LookUp", this, &AC_PlayerController::RotatePitch);
		InputComponent->BindAction("Jump",IE_Pressed ,this, &AC_PlayerController::Jump);
		InputComponent->BindAction("Sprint", IE_Pressed, this, &AC_PlayerController::Sprint);
		InputComponent->BindAxis("Down", this, &AC_PlayerController::Down);
		InputComponent->BindAction("Interact", IE_Pressed, this, &AC_PlayerController::Interact);
	}
}

void AC_PlayerController::MoveForward(float moveAmount)
{
	LastMovementInput.X += moveAmount;
}

void AC_PlayerController::MoveRight(float moveAmount)
{
	LastMovementInput.Y += moveAmount;
}

void AC_PlayerController::RotateYaw(float rotateAmount)
{
	LastRoataionInput.X += rotateAmount;
}

void AC_PlayerController::RotatePitch(float rotateAmount)
{
	LastRoataionInput.Y += rotateAmount;
}

void AC_PlayerController::Jump()
{
	PossessedWorrior->Jump();
}

void AC_PlayerController::Sprint()
{
	UUniversalFunctions::PrintMsg("shift ie pressed");
}

void AC_PlayerController::Interact()
{
	AWarrior* PossessedAWorrior = Cast<AWarrior>(PossessedWorrior);
	if (PossessedAWorrior)
	{
		UUniversalFunctions::PrintMsg("well, this one is coverted");
		PossessedAWorrior->TryInteract();
	}
}

void AC_PlayerController::Down(float DownAmount)
{
	if (DownAmount)
	{
		UUniversalFunctions::PrintMsg("downing");
	}
}

void AC_PlayerController::ChangeCharacter()
{
	if (PossessedWorrior)
	{
		int warriorAmount = warriorTemplates.Num();
		if (warriorAmount > 1)
		{
			currentWorrierIndex += 1;
			currentWorrierIndex = currentWorrierIndex % warriorAmount;
			UUniversalFunctions::PrintMsg("Changing character to: " + FString::FromInt(currentWorrierIndex));
		}
		else
		{
			UUniversalFunctions::PrintMsg("Nothing to change to");
			return;
		}
		PossessedWorrior->SetActorEnableCollision(false);
		PossessedWorrior->SetActorHiddenInGame(true);
		ACharacter* NewWarriorToPossess = SpawnWarrior(warriorTemplates[currentWorrierIndex]);
		Possess(NewWarriorToPossess);
		PossessedWorrior->Destroy();
		PossessedWorrior = NewWarriorToPossess;
	}
}

ACharacter* AC_PlayerController::SpawnWarrior(TSubclassOf<ACharacter> Template)
{
	UUniversalFunctions::PrintMsg("Spawning Worrier");
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	FTransform SpawnPosition;
	SpawnPosition.SetLocation(GetPawn()->GetActorLocation());
	return GetWorld()->SpawnActor<ACharacter>(Template,SpawnPosition,SpawnInfo);
}

void AC_PlayerController::NormalizeInput()
{
	{
		float len = LastMovementInput.Size();
		if (len > 1.0f)
		{
			LastMovementInput /= len;
		}
	}
	{
		float len = LastRoataionInput.Size();
		if (len > 1.0f)
		{
			LastRoataionInput /= len;
		}
	}
}

bool AC_PlayerController::IsPlayerMoved()
{
	if (LastMovementInput.Size() != 0)
	{
		return true;
	}
	return false;
}

bool AC_PlayerController::IsPlayerRotated()
{
	if (LastRoataionInput.Size() != 0)
	{
		return true;
	}
	return false;
}

void AC_PlayerController::createButton()
{
	//create a new sverticalBox using a shared reference because it is defined this way.
	TSharedRef<SVerticalBox> widget = SNew(SVerticalBox) + SVerticalBox::Slot()//give it a slot
		.HAlign(HAlign_Center)//set the slot to be centered horizontally
		.VAlign(VAlign_Center)//set the slot to be centered vertically
							  //using square brackets, we create a button that has textblock inside it
		[
			SNew(SButton).Content()
			[
				SNew(STextBlock).Text(FText::FromString(TEXT("test button")))
			]
		];
	if (GEngine)
	{
		GEngine->GameViewport->AddViewportWidgetForPlayer(GetLocalPlayer(), widget, 1);
	}
}


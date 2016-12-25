// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "UniversalFunctions.h"
#include "C_PlayerController.h"
#include "Interfaces/Talker.h"
#include "Interactable/IFInteractable.h"
#include "WorriedEathen.h"

AWorriedEathen::AWorriedEathen()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	CameraBoom->bUsePawnControlRotation = true;

	TalkCollider = CreateDefaultSubobject<UBoxComponent>("TalkCollider");
	TalkCollider->SetBoxExtent(FVector(200, 200, 100));
	TalkCollider->OnComponentBeginOverlap.AddDynamic(this, &AWorriedEathen::OnTalkerOverLap);
	TalkCollider->SetupAttachment(RootComponent);
}

void AWorriedEathen::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	
}

void AWorriedEathen::updateMovement()
{
	AC_PlayerController* MyController = (AC_PlayerController*)GetController();
	//Update Movement
	{
		// find out which way is forward
		const FRotator Rotation = MyController->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector forwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		
		if (MyController && MyController->IsPlayerMoved())
		{
			AddMovementInput(forwardDirection, MyController->LastMovementInput.X);
			AddMovementInput(RightDirection, MyController->LastMovementInput.Y);
			MyController->LastMovementInput = FVector2D(0.0f, 0.0f);
		}
	}
	
	//Update Rotation
	{
		if (MyController && MyController->IsPlayerRotated())
		{
			AddControllerYawInput(MyController->LastRoataionInput.X);
			AddControllerPitchInput(MyController->LastRoataionInput.Y);
			MyController->LastRoataionInput = FVector2D(0.0f, 0.0f);
		}
	}
}

void AWorriedEathen::OnTalkerOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ITalker* TalkingActor = Cast<ITalker>(OtherActor);
	if (TalkingActor != nullptr)
	{
		ITalker::Execute_StartTalking(OtherActor);
	}
}

void AWorriedEathen::TryInteract()
{
	APlayerController* MyController = Cast<APlayerController>(Controller);
	if (MyController)
	{
		APlayerCameraManager* MyCameraManager = MyController->PlayerCameraManager;
		FVector StartLocation = GetActorLocation();
		FVector EndLocation = StartLocation + GetActorForwardVector() * 100.0f;
		FHitResult HitResult;
		UWorld* MyWorld = GetWorld();
		if (MyWorld)
		{
			
			bool bTryHitSomething =
				MyWorld->SweepSingleByObjectType(
				HitResult,
				StartLocation,
				EndLocation,
				FQuat::Identity,
				FCollisionObjectQueryParams(FCollisionObjectQueryParams::AllObjects), 
				FCollisionShape::MakeSphere(25),
				FCollisionQueryParams(FName("Interaction"),
								   	true,
									this
									 )
			);
			if (bTryHitSomething && HitResult.Actor->GetClass()->ImplementsInterface(UIFInterable::StaticClass()))
			{
				if (IIFInterable::Execute_CanInteract(HitResult.Actor.Get()))
				{
					IIFInterable::Execute_PerformInteract(HitResult.Actor.Get());
				}
			}
		}
	}
}


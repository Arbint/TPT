// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "TPT.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "UniversalFunctions.h"
#include "Weapon_Base.h"
#include "NoneNativeClass.h"
#include "SpawnerComponent.h"
#include "InventoryComponent.h"
#include "InventoryActor.h"
#include "TPTCharacter.h"


//////////////////////////////////////////////////////////////////////////
// ATPTCharacter

ATPTCharacter::ATPTCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
	TheSpawnerComponent = CreateDefaultSubobject<USpawnerComponent>(TEXT("Spawning Loc"));
	TheSpawnerComponent->SetupAttachment(RootComponent);
	TheSpawnerComponent->SetRelativeLocation(FVector(80.0f, 0.0f, 0.0f));

	MyInventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("MyInventory"));
}

AWeapon_Base* ATPTCharacter::CreateWeapon()
{
	AWeapon_Base* NewWeapon = GetWorld()->SpawnActor<AWeapon_Base>(UClassOfAxe);
	return NewWeapon;
}


void ATPTCharacter::DeleteWeapon()
{
	if (weaponInventory.Num() > 0)
	{
		UUniversalFunctions::PrintMsg("Number is bigger than 0");
		AWeapon_Base* weaponToDelete = weaponInventory[0];
		weaponInventory.RemoveSingle(weaponToDelete);
		weaponToDelete->ConditionalBeginDestroy();
	}
}

void ATPTCharacter::DeleteUnvFuc()
{
	if (UnversalObjects.Num() > 0)
	{
		UUniversalFunctions* fucToDelete = UnversalObjects[0];
		if (fucToDelete)
		{
			UnversalObjects.RemoveSingle(fucToDelete);
			fucToDelete->DestoryIt();
		}
	}
}

void ATPTCharacter::CreateAxeOnMe(float height)
{
	AWeapon_Base* AxeWeapon = CreateWeapon();
	FVector AxeLocation = GetActorLocation() + FVector(0,0, height);
	AxeWeapon->SetActorLocation(AxeLocation);
	weaponInventory.Add(AxeWeapon);
}

void ATPTCharacter::CreateUnversalFunction()
{
	UUniversalFunctions* NewFunction = NewObject<UUniversalFunctions>(GetTransientPackage(), UUniversalFunctions::StaticClass());
	NewFunction->PrintMsg("I got created!!");
	UnversalObjects.Add(NewFunction);
}

void ATPTCharacter::TrySmartPtrWithClass()
{
		NoneNativeClass* ClassObjectRawPtr{ new NoneNativeClass(11,TEXT("JT")) };
		TSharedPtr<NoneNativeClass> newClassObject{ new NoneNativeClass(10, TEXT("JG")) };
}

void ATPTCharacter::DropItem()
{
	if (MyInventory->CurrentInventory.Num() == 0)
	{
		return;
	}

	AInventoryActor* Item = MyInventory->CurrentInventory.Last();
	MyInventory->RemoveFromInventory(Item);
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->putDown(PutDownLocation, RootComponent->GetForwardVector());

}

void ATPTCharacter::TakeItem(AInventoryActor* InventoryItem)
{
	InventoryItem->Pickup(this);
	MyInventory->AddToInventory(InventoryItem);
	InventoryItem->GetStaticMeshComponent()->SetupAttachment(RootComponent);
}

void ATPTCharacter::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComponent, bool bSelfMoved, FVector HitLocaiton, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	AInventoryActor* InventoryItem = Cast<AInventoryActor>(Other);
	if (InventoryItem != nullptr)
	{
		TakeItem(InventoryItem);
	}
	Super::NotifyHit(MyComp,Other,OtherComponent,bSelfMoved,HitLocaiton,HitNormal,NormalImpulse,Hit);
}

//////////////////////////////////////////////////////////////////////////
// Input

void ATPTCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATPTCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATPTCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ATPTCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ATPTCharacter::LookUpAtRate);
	

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ATPTCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ATPTCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ATPTCharacter::OnResetVR);

	//
	InputComponent->BindAction("DropItem", IE_Pressed, this, &ATPTCharacter::DropItem);
}


void ATPTCharacter::PrintName() const
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("I am not happy"));
	}
}

void ATPTCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ATPTCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void ATPTCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void ATPTCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ATPTCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ATPTCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ATPTCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

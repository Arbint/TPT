// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "CAIController.h"
#include "FollowerCharacter.h"


// Sets default values
AFollowerCharacter::AFollowerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USkeletalMeshComponent* meshComp = GetMesh();
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("SkeletalMesh'/Game/MixamoAnimPack/Mixamo_Kachujin/Mesh/Kachujin_G_Rosales.Kachujin_G_Rosales'"));
	if (MeshAsset.Succeeded())
	{
		meshComp->SetSkeletalMesh(MeshAsset.Object);
	}
	meshComp->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -90.f), FRotator(0.0f, -90.0f, 0.f).Quaternion());
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBlueprintAsset(TEXT("AnimBlueprint'/Game/MixamoAnimPack/Mixamo_Kachujin/Anims/MixamoAnimBP_Kachujin.MixamoAnimBP_Kachujin'"));
	if (AnimBlueprintAsset.Succeeded())
	{
		meshComp->SetAnimInstanceClass(AnimBlueprintAsset.Object->GeneratedClass);
	}
	AIControllerClass = ACAIController::StaticClass();
}

// Called when the game starts or when spawned
void AFollowerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFollowerCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

// Called to bind functionality to input
void AFollowerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


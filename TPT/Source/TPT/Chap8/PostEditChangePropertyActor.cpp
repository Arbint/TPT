// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "UniversalFunctions.h"
#include "PostEditChangePropertyActor.h"




APostEditChangePropertyActor::APostEditChangePropertyActor()
{
	bShowStaticMesh = true;
	anotherMesh = CreateDefaultSubobject<UStaticMeshComponent>("AnotherMesh");
	anotherMesh->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	anotherMesh->SetMobility(EComponentMobility::Movable);
	anotherMesh->bGenerateOverlapEvents = true;
	anotherMesh->SetupAttachment(RootComponent);
}

void APostEditChangePropertyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.Property != nullptr)
	{
		const FName PropertyName = PropertyChangedEvent.MemberProperty->GetFName();
		if (PropertyName == GET_MEMBER_NAME_CHECKED(APostEditChangePropertyActor, bShowStaticMesh))
		{
			if (GetStaticMeshComponent() != nullptr)
			{
				GetStaticMeshComponent()->SetVisibility(bShowStaticMesh);
			}
		}
	}
	if (PropertyChangedEvent.Property != nullptr)
	{
		const FName propertyName = PropertyChangedEvent.MemberProperty->GetFName();
		
		if (propertyName == GET_MEMBER_NAME_CHECKED(APostEditChangePropertyActor, AnotherMeshRelativeLocation))
		{
			if (anotherMesh != nullptr)
			{
				anotherMesh->SetRelativeLocation(AnotherMeshRelativeLocation);
			}
		}
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void APostEditChangePropertyActor::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	UUniversalFunctions::PrintMsg("I got hittttttt!");
}

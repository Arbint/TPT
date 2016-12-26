// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "TestInterface.h"
#include "MyGameMode.generated.h"

class AWarrior;

class AWeapon_Base;

/**
 * 
 */
DECLARE_DELEGATE(FStandardDelegateSignature)

DECLARE_DELEGATE_OneParam(FOnePramSignature, FLinearColor)

DECLARE_MULTICAST_DELEGATE(FMyMullticastSignature)

UCLASS()
class TPT_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
		
		
public:
	AMyGameMode();
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EEndPlayReason) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorToGenerate")
		TSubclassOf<AWeapon_Base> weaponToGenerate;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
		TSubclassOf<AWarrior> defaultCharacterToSpawn;

	UPROPERTY()
		AWeapon_Base* SpawnedAxe;

	FStandardDelegateSignature MyStandardDelegate;
	FOnePramSignature MyOneParmDelegate;
	FMyMullticastSignature MyMulticastDelegate;

	UPROPERTY()
		TArray<AActor*> MyInterfaceInstances;


	void FindActorsUsingInerface();

	UPROPERTY()
		FTimerHandle HUDToggleTimer;


	UFUNCTION()
		void createBlinkingButtion();

private:
	TSharedPtr<SVerticalBox> Widget;
	TSharedPtr<STextBlock> ButtonLabel;

public:
	FReply ButtonClicked();
	UFUNCTION()
		void createClickableButton();

	UFUNCTION()
		FText GetButtonLabel() const;
};

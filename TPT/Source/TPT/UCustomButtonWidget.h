// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/Widget.h"
#include "UI/CustomButton.h"
#include "SlateDelegates.h"
#include "UCustomButtonWidget.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FButtonCliced);
DECLARE_DYNAMIC_DELEGATE_RetVal(FString, FGetString);

UCLASS()
class TPT_API UUCustomButtonWidget : public UWidget
{
	GENERATED_BODY()

protected:
	TSharedPtr<SCustomButton> MyButton;
	virtual TSharedRef<SWidget> RebuildWidget() override;
public:
	UUCustomButtonWidget();

	UPROPERTY(BlueprintAssignable)
		FButtonCliced ButtonClicked;

	FReply OnButtonClicked();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString Label;

	UPROPERTY()
		FGetString LabelDelegate;

	virtual void SynchronizeProperties() override;
};

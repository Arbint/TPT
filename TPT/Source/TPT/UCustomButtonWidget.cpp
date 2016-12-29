// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "UCustomButtonWidget.h"


TSharedRef<SWidget> UUCustomButtonWidget::RebuildWidget()
{
	MyButton = SNew(SCustomButton).ButtonClicked(BIND_UOBJECT_DELEGATE(FOnClicked, OnButtonClicked));
	return MyButton.ToSharedRef();
}

UUCustomButtonWidget::UUCustomButtonWidget()
	:Label(TEXT("Default Value"))
{

}

FReply UUCustomButtonWidget::OnButtonClicked()
{
	ButtonClicked.Broadcast();
	return FReply::Handled();
}

void UUCustomButtonWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	TAttribute<FString> LabelBinding = OPTIONAL_BINDING(FString, Label);
	MyButton->Label = LabelBinding;
}


// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "NoneNativeClass.h"

NoneNativeClass::NoneNativeClass()
{
}

NoneNativeClass::NoneNativeClass(int Hp, FString Nm)
	:HpValue(Hp), Name(Nm)
{
	UUniversalFunctions::PrintMsg(Name + " got Created");
}

int NoneNativeClass::GetValue()
{
	return HpValue;
}

FString NoneNativeClass::GetName()
{
	return Name;
}

NoneNativeClass::~NoneNativeClass()
{
	FString DeadMessage = Name + TEXT(" Is cruly dead because of Scope");
	UUniversalFunctions::PrintMsg(DeadMessage);
}

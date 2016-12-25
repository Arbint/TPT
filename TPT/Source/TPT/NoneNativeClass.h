// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TPT.h"
#include "UniversalFunctions.h"
/**
 * 
 */

class TPT_API NoneNativeClass
{
public:
	int HpValue;
	FString Name;
	NoneNativeClass();
	NoneNativeClass(int Hp, FString Nm);
	int GetValue();
	FString GetName();
	~NoneNativeClass();
};

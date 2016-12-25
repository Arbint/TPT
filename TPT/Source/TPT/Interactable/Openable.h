#pragma once
#include "Openable.generated.h"

UINTERFACE()
class TPT_API UOpenable : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class TPT_API IOpenable
{
	GENERATED_IINTERFACE_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Openable)
	void Open();
};
#pragma once
#include "IFInteractable.generated.h"

UINTERFACE()
class TPT_API UIFInterable : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class TPT_API IIFInterable
{
	GENERATED_IINTERFACE_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Interactable)
	bool CanInteract();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Interactable)
	void PerformInteract();
};
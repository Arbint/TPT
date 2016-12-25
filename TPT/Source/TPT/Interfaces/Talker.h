#pragma once
#include "Talker.generated.h"

UINTERFACE()
class TPT_API UTalker : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class TPT_API ITalker
{
	GENERATED_IINTERFACE_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Talk)
	void StartTalking();

};
#pragma once
#include "GravityObject.generated.h"

UINTERFACE()
class TPT_API UGravityObject : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class TPT_API IGravityObject
{
	GENERATED_IINTERFACE_BODY()

	UFUNCTION()
		virtual void EnableGravity();
	UFUNCTION()
		virtual void  DisableGravity();
};

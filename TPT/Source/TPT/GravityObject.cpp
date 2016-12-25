#include "TPT.h"
#include "GravityObject.h"

UGravityObject::UGravityObject(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

}

void IGravityObject::EnableGravity()
{
	AActor* ThisAsActor = Cast<AActor>(this);
	if (ThisAsActor)
	{
		TArray<UPrimitiveComponent*> AllPrimitiveComponent;
		ThisAsActor->GetComponents(AllPrimitiveComponent);
		for (UPrimitiveComponent* Component : AllPrimitiveComponent)
		{
			Component->SetEnableGravity(true);
			Component->AddImpulse(FVector(0.0f, 1000.0f, 0.0f));
		}
	}
}

void IGravityObject::DisableGravity()
{
	AActor* ThisAsActor = Cast<AActor>(this);
	if (ThisAsActor)
	{
		TArray<UPrimitiveComponent*> AllPrimitiveComponent;
		ThisAsActor->GetComponents(AllPrimitiveComponent);
		for (UPrimitiveComponent* Component : AllPrimitiveComponent)
		{
			Component->SetEnableGravity(false);
			
		}
	}
}

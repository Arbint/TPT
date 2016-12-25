#include "TPT.h"
#include "IFInteractable.h"

UIFInterable::UIFInterable(const FObjectInitializer& ObjectInitialzer)
	:Super(ObjectInitialzer)
{

}

bool IIFInterable::CanInteract_Implementation()
{
	return true;
}

void IIFInterable::PerformInteract_Implementation()
{

}

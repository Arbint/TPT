#include "TPT.h"
#include "UniversalFunctions.h"
#include "Talker.h"

UTalker::UTalker(const FObjectInitializer& ObjectInitialzer)
	:Super(ObjectInitialzer)
{

}

void ITalker::StartTalking_Implementation()
{
	UUniversalFunctions::PrintMsg("OK, Now I got called");
}

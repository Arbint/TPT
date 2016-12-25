#pragma once
#include "TestInterface.generated.h"



UINTERFACE()
class TPT_API UTestInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class TPT_API ITestInterface
{
	GENERATED_IINTERFACE_BODY()
public:
	//classes using this interface must implement ReacthToHighMoon
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyCategory")
		bool ReactToHighMoon();

	//classes using this interface may implement ReactToMidNight
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "MyCategory")
	 bool ReactToMidnight();

};
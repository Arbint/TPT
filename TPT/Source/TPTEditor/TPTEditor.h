#pragma once

#include "Engine.h"
#include "ModuleManager.h"
#include "UnrealEd.h"


DECLARE_LOG_CATEGORY_EXTERN(TPTEditor, All, All)

class FTPTEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
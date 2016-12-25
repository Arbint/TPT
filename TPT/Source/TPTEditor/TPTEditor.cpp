#include "TPTEditor.h"

IMPLEMENT_GAME_MODULE(FTPTEditorModule, TPTEditor)

DEFINE_LOG_CATEGORY(TPTEditor)

#define LOCTEXT_NAMESPACE "TPTEditor"


void FTPTEditorModule::StartupModule()
{
	UE_LOG(TPTEditor, Warning, TEXT("TPTEditor: Log Started"));
}

void FTPTEditorModule::ShutdownModule()
{
	UE_LOG(TPTEditor, Warning, TEXT("TPTEditor: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
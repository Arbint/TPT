// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TPTEditor : ModuleRules
{
    public TPTEditor(TargetInfo Target)
    {
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
        PublicDependencyModuleNames.Add("TPT");
        PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd" });
    }
}

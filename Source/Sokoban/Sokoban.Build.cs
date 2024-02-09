// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Sokoban : ModuleRules
{
	public Sokoban(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });
        PublicDependencyModuleNames.AddRange(new string[] { "Json", "JsonUtilities" });
    }
}

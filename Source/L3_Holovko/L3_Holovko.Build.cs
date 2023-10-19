// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class L3_Holovko : ModuleRules
{
	public L3_Holovko(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}

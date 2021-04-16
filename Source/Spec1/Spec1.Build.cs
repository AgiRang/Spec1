// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Spec1 : ModuleRules
{
	public Spec1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}

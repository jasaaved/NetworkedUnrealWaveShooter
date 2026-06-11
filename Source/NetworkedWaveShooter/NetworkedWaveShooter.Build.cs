// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NetworkedWaveShooter : ModuleRules
{
	public NetworkedWaveShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"NetworkedWaveShooter",
			"NetworkedWaveShooter/Variant_Horror",
			"NetworkedWaveShooter/Variant_Horror/UI",
			"NetworkedWaveShooter/Variant_Shooter",
			"NetworkedWaveShooter/Variant_Shooter/AI",
			"NetworkedWaveShooter/Variant_Shooter/UI",
			"NetworkedWaveShooter/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

// Copyright SkyHigh Gaming.

using UnrealBuildTool;
using System.Collections.Generic;

public class AstraProject03Target : TargetRules
{
	public AstraProject03Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "AstraProject03" } );
	}
}

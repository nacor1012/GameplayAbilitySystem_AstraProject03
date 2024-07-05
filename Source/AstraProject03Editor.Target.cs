// Copyright SkyHigh Gaming.

using UnrealBuildTool;
using System.Collections.Generic;

public class AstraProject03EditorTarget : TargetRules
{
	public AstraProject03EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "AstraProject03" } );
	}
}

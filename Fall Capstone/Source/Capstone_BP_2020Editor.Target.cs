// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Capstone_BP_2020EditorTarget : TargetRules
{
	public Capstone_BP_2020EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Capstone_BP_2020" } );
	}
}

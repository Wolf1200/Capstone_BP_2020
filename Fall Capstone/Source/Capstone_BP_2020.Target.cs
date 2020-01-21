// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Capstone_BP_2020Target : TargetRules
{
	public Capstone_BP_2020Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Capstone_BP_2020" } );
	}
}

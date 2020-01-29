// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Capstone_2020GameMode.h"
#include "Capstone_2020Character.h"
#include "UObject/ConstructorHelpers.h"

ACapstone_2020GameMode::ACapstone_2020GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

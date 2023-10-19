// Copyright Epic Games, Inc. All Rights Reserved.

#include "L3_HolovkoGameMode.h"
#include "L3_HolovkoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AL3_HolovkoGameMode::AL3_HolovkoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

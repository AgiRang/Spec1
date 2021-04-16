// Copyright Epic Games, Inc. All Rights Reserved.

#include "Spec1GameMode.h"
#include "Spec1Character.h"
#include "UObject/ConstructorHelpers.h"

ASpec1GameMode::ASpec1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

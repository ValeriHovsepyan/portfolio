// Copyright Epic Games, Inc. All Rights Reserved.

#include "SnakeGameMode.h"
#include "SnakeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASnakeGameMode::ASnakeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

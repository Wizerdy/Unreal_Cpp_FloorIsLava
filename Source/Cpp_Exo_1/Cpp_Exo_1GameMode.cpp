// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cpp_Exo_1GameMode.h"
#include "Cpp_Exo_1Character.h"
#include "UObject/ConstructorHelpers.h"

ACpp_Exo_1GameMode::ACpp_Exo_1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "FPSHUD.h"
#include "FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

AFPSGameMode::AFPSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_Player"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSHUD::StaticClass();
}

void AFPSGameMode::CompleteMission(APawn* InstigatorPawn)
{
	if (InstigatorPawn)
	{
		InstigatorPawn->DisableInput(nullptr);
		TArray<AActor*> SpectatorClass;
		UGameplayStatics::GetAllActorsOfClass(this, SpectatingController, SpectatorClass);

		if (SpectatorClass.Num() > 0)
		{
			AActor* NewViewPoint = SpectatorClass[0];

			APlayerController* PlayerControl = Cast<APlayerController>(InstigatorPawn->GetController());
			if (PlayerControl)
			{
				PlayerControl->SetViewTargetWithBlend(NewViewPoint, 0.5f, VTBlend_Cubic);
			}
			
		}
	}

	OnMissionCompleted(InstigatorPawn);
}
 
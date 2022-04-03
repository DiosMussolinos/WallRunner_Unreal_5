// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerController.h"
#include "WallRunCharacter.h"

//Get Pawn
void ARunnerController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);

	if (pawn && pawn->IsA<AWallRunCharacter>())
	{
		runnerChar = (AWallRunCharacter*)pawn;
		runnerChar->SelfReference = runnerChar;
	}
}
//_______/
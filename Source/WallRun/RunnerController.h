// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RunnerController.generated.h"

/**
 * 
 */
UCLASS()
class WALLRUN_API ARunnerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void OnPossess(APawn* pawn) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class AWallRunCharacter* runnerChar;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FallingZone.generated.h"

UCLASS()
class WALLRUN_API AFallingZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFallingZone();

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Return Home")
		AActor* emptyActor;


	void NotifyActorBeginOverlap(AActor* OtherActor);

};

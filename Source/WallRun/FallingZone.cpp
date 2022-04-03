// Fill out your copyright notice in the Description page of Project Settings.


#include "FallingZone.h"
#include "WallRunCharacter.h"

// Sets default values
AFallingZone::AFallingZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFallingZone::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OtherActor)
	{
		if (OtherActor->IsA<AWallRunCharacter>())
		{
			OtherActor->SetActorLocation(emptyActor->GetActorLocation());
		}
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnableWall.h"
#include "WallRunCharacter.h"
#include "Engine.h"
#include "Net/UnrealNetwork.h"


// Sets default values
ARunnableWall::ARunnableWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARunnableWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARunnableWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARunnableWall::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OtherActor)
	{
		if (OtherActor->IsA<AWallRunCharacter>())
		{
			//Affect Wall (Make it unwakable until the character leaves)
			walking = true;

			AWallRunCharacter* CastRunner = Cast<AWallRunCharacter>(OtherActor);
			CastRunner->canWalk = true;
			CastRunner->wall = this;
		}
	}
}

void ARunnableWall::NotifyActorEndOverlap(AActor* OtherActor)
{
	if (OtherActor)
	{
		if (OtherActor->IsA<AWallRunCharacter>())
		{
			walking = false;

			AWallRunCharacter* CastRunner = Cast<AWallRunCharacter>(OtherActor);
			CastRunner->canWalk = false;
			CastRunner->wall = nullptr;
		}
	}
}

void ARunnableWall::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ARunnableWall, walking);
}
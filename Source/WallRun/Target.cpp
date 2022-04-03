// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"
#include "WallRunCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATarget::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OtherActor)
	{
		if (OtherActor->IsA<AWallRunCharacter>())
		{
			if (!hit)
			{
				AWallRunCharacter* CastRunner = Cast<AWallRunCharacter>(OtherActor);

				CastRunner->targets.Add(this);
			}
		}
	}
}

void ATarget::NotifyActorEndOverlap(AActor* OtherActor)
{

	if (OtherActor)
	{
		if (OtherActor->IsA<AWallRunCharacter>())
		{
			AWallRunCharacter* CastRunner = Cast<AWallRunCharacter>(OtherActor);

			CastRunner->targets.Remove(this);
		}
	}
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (hit)
	{
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWallRunCharacter::StaticClass(), FoundActors);

		for (int i = 0; i < FoundActors.Num(); i++)
		{
			AWallRunCharacter* RunnerCast = Cast<AWallRunCharacter>(FoundActors[i]);

			for (int j = 0; j < RunnerCast->targets.Num(); j++)
			{
				if (RunnerCast->targets[j] == this)
				{
					RunnerCast->targets.Remove(this);
					break;
				}
			}
		}
	}
}

void ATarget::HitFunction(bool toChange)
{
	hit = toChange;
}

void ATarget::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATarget, hit);
}


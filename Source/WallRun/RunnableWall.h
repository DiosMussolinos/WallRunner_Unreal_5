// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RunnableWall.generated.h"


UCLASS()
class WALLRUN_API ARunnableWall : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARunnableWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Replicated, BlueprintReadWrite, Category = "Targets")
	bool walking = false;

	void NotifyActorBeginOverlap(AActor* OtherActor);

	void NotifyActorEndOverlap(AActor* OtherActor);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

};

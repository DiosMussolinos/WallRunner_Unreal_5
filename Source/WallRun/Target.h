// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

UCLASS()
class WALLRUN_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void NotifyActorBeginOverlap(AActor* OtherActor);
	void NotifyActorEndOverlap(AActor* OtherActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HitFunction(bool toChange);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Values")
		int value = 1;

	UPROPERTY(EditAnywhere, Replicated, BlueprintReadWrite, Category = "Values")
		bool hit = false;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

};

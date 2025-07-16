// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformBase.h"
#include "PlatformSpawner.generated.h"

UCLASS()
class ASSIGNMENT6_API APlatformSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere)
	TSubclassOf<APlatformBase> PlatformToSpawn;

	UPROPERTY(EditAnywhere)
	int32 Count = 5;

	UPROPERTY(EditAnywhere)
	FVector SpawnMin = FVector(-800, -800, 100);

	UPROPERTY(EditAnywhere)
	FVector SpawnMax = FVector(800, 800, 800);
};

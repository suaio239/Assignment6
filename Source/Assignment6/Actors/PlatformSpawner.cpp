// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformSpawner.h"

#include "PlatformBase.h"
#include "MovingPlatform.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
APlatformSpawner::APlatformSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APlatformSpawner::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < Count; ++i)
	{
		FVector Pos = UKismetMathLibrary::RandomPointInBoundingBox(
			(SpawnMin + SpawnMax) / 2,
			(SpawnMax - SpawnMin) / 2
		);

		FRotator Rotator = FRotator(0, FMath::RandRange(0.f, 360.f), 0);

		APlatformBase* Spawned = GetWorld()->SpawnActor<APlatformBase>(PlatformToSpawn, Pos, Rotator);

		if (Spawned)
		{
			if (auto Moving = Cast<AMovingPlatform>(Spawned))
			{
				Moving->MoveDistance = FMath::RandRange(200.f, 1000.f);
				Moving->Speed = FMath::RandRange(100.f, 300.f);
			}
		}
	}
	
}


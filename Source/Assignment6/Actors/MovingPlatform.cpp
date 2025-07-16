// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "DrawDebugHelpers.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	TargetLocation = StartLocation + GetActorForwardVector() * MoveDistance;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FVector Target = bForward ? TargetLocation : StartLocation;

	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, Target, DeltaTime, Speed);
	SetActorLocation(NewLocation);
	if (FVector::Dist(NewLocation, Target) < 5.f)
		bForward = !bForward;

	// 에셋 움직이는 위치 디버깅
	DrawDebugLine(
		GetWorld(),
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * 100.0f,
		FColor::Red,
		false, 0.5f, 0, 2.0f
	);
}


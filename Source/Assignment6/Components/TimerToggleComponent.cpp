// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerToggleComponent.h"

// Sets default values for this component's properties
UTimerToggleComponent::UTimerToggleComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTimerToggleComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&UTimerToggleComponent::ToggleTimer,
		ToggleInterval,
		true
		);	
}

void UTimerToggleComponent::ToggleTimer()
{
	bToggle = !bToggle;
}


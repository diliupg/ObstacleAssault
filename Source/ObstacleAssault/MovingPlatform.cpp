// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform():
	PlatformVelocity(400.f,0.f,0.f),
	MaxMoveDistance(6000.f)

{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	// move the platform forward
		// get current location
	FVector CurrentLocation = GetActorLocation();
		// add vector to location
	CurrentLocation += PlatformVelocity * DeltaTime;
		// set the location
	SetActorLocation(CurrentLocation);
		// send the platform back if it reached planned destination
		// check how far we have moved
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
		// if target reached reverse direction
	if (DistanceMoved > MaxMoveDistance)
	{
		PlatformVelocity = -PlatformVelocity;
		StartLocation = CurrentLocation;
	}

		// if reached the starting point do from beginning again

}



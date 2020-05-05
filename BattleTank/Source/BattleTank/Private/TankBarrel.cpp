// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
	auto ElevationChange = FMath::Clamp<float>(RelativeSpeed, -1, 1) * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = GetRelativeRotation().Pitch + ElevationChange;
	SetRelativeRotation(FRotator(FMath::Clamp<float>(RawNewElevation, MinDegreesElevation, MaxDegreesElevation), 0, 0));
}
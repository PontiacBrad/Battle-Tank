// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime) // Tick
{
	Super::Tick(DeltaTime);  //Super
	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Ticking"));
}
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	PrimaryActorTick.bCanEverTick = true;

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not posessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("No Controlled Tank"));
		return;
	}
	FVector HitLocation; // Out Parameter

	if (GetSightRayHitLocation(HitLocation))  // Has "side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
			// TODO Tell controlled tank to aim at this point
	}
}
// Get world location of linetrace through crosshair, true if hits landscape

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}
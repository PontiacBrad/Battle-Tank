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
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
			// TODO Tell controlled tank to aim at this point
	}
}
// Get world location of linetrace through crosshair, true if hits landscape

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//OutHitLocation = FVector(1.0);
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
	// "De-project" the screen position of the crosshair to a world direction
	// Line-trace along that look direction, and see what we hit (up to a max range)
	return true;
}
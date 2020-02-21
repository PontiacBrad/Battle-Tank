// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetPlayerTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(ControlledTank->GetName()));
	}
	//UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));
}
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerTank)
	{
		return nullptr;
	}
	else
	{
		return Cast<ATank>(PlayerTank);
	}
}
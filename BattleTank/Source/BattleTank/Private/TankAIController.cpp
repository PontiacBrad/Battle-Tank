// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//auto ControlledTank = GetPlayerTank();

	//if (!ControlledTank)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(ControlledTank->GetName()));
	//}
	//UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));
}
//ATank* ATankAIController::GetControlledTank() const
//{
//	return 
//}
//ATank* ATankAIController::GetPlayerTank() const
//{
//	auto PlayerTank = ;
//
//	if (!PlayerTank)
//	{
//		return nullptr;
//	}
//	else
//	{
//		return Cast<ATank>(PlayerTank);
//	}
//}
// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		// Fire if ready
		ControlledTank->Fire(); // TODO limit firing rate
	}
}
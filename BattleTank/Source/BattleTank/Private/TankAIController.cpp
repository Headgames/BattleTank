// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();

	auto GetTheControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (GetTheControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI possesses Tank: %s"), *GetTheControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI does not possess a Tank"));
	}

	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank found."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank not found."));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
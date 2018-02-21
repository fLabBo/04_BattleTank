// Fill out your copyright notice in the Description page of Project Settings.

#include "BTGame.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not find a player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found Player tank: %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	// returns tank pawn the player controller is possessing
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerController = GetWorld()->GetFirstPlayerController();
	if (!PlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Warning, no player tank exists"));
		return nullptr;
	}
		
	auto PlayerTank = Cast<ATank>(PlayerController->GetControlledPawn());

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController %s is not posessing a Tank Pawn"), *(PlayerController->GetName()));
	}

	return PlayerTank;
}


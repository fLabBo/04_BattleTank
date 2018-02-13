// Fill out your copyright notice in the Description page of Project Settings.

#include "BTGame.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	// returns tank pawn the player controller is possessing
	return Cast<ATank>(GetPawn());
}

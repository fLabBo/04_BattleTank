// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BTGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public: 
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;
};

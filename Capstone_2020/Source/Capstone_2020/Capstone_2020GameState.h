// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/GameStateBase.h"
#include "Capstone_2020GameState.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTONE_2020_API ACapstone_2020GameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	ACapstone_2020GameState();

	UDataTable* GetItemDB() const;

protected:
	UPROPERTY(EditDefaultsOnly)
	class UDataTable* ItemDB;
};

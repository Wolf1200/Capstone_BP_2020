// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Interactable.h"
#include "InventoryItem.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Capstone_2020Controller.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTONE_2020_API ACapstone_2020Controller : public APlayerController
{
	GENERATED_BODY()

public:
	ACapstone_2020Controller();

	UFUNCTION(BlueprintImplementableEvent)
		void ReloadInventory();

	UFUNCTION(BlueprintCallable, Category = "Utils")
		int32 GetInventoryWeight();

	UFUNCTION(BlueprintCallable, Category = "Utils")
		bool AddItemToInventoryByID(FName ID);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class AInteractable* CurrentInteractable;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<FInventoryItem> Inventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int32 Money;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 InventorySlotLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 InventoryWeightLimit;

protected:
	void Interact();

	virtual void SetupInputComponent() override;
	
};

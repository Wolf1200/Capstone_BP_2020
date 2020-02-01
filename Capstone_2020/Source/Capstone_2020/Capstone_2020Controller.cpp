// Fill out your copyright notice in the Description page of Project Settings.


#include "Capstone_2020Controller.h"

#include "Capstone_2020GameState.h"
#include "Capstone_2020Character.h"

ACapstone_2020Controller::ACapstone_2020Controller()
{
	InventorySlotLimit = 50;
	InventoryWeightLimit = 500;
}

int32 ACapstone_2020Controller::GetInventoryWeight()
{
	int32 Weight = 0;
	for (auto& Item : Inventory)
	{
		Weight += Item.Weight;
	}

	return Weight;
}

bool ACapstone_2020Controller::AddItemToInventoryByID(FName ID)
{
	ACapstone_2020GameState* GameState = Cast<ACapstone_2020GameState>(GetWorld()->GetGameState());
	UDataTable* ItemTable = GameState->GetItemDB();
	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	if (ItemToAdd)
	{
		// If a Slot- or WeightLimit are not needed remove them in this line
		if (Inventory.Num() < InventorySlotLimit && GetInventoryWeight() + ItemToAdd->Weight <= InventoryWeightLimit)
		{
			Inventory.Add(*ItemToAdd);
			ReloadInventory();
			return true;
		}
	}
	return false;
}

void ACapstone_2020Controller::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Interact", IE_Pressed, this, &ACapstone_2020Controller::Interact);
}

void ACapstone_2020Controller::Interact()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact(this);
	}
}
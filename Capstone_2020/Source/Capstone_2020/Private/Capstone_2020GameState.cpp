// Fill out your copyright notice in the Description page of Project Settings.


#include "Capstone_2020GameState.h"

ACapstone_2020GameState::ACapstone_2020GameState()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> BP_ItemDB(TEXT("DataTable'/Game/Data/ItemDB.ItemDB'"));
	ItemDB = BP_ItemDB.Object;
}

UDataTable* ACapstone_2020GameState::GetItemDB() const
{
	return ItemDB;
}
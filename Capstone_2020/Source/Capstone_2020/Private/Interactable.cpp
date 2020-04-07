// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"
#include "Capstone_2020Controller.h"
#include "GameFramework/Controller.h"

AInteractable::AInteractable()
{
	Name = "Interactable";
	Action = "interact";
}

void AInteractable::Interact_Implementation(APlayerController* Controller)
{
	return;
}

FString AInteractable::GetInteractText() const
{
	return FString::Printf(TEXT("%s: Press F to %s"), *Name, *Action);
}

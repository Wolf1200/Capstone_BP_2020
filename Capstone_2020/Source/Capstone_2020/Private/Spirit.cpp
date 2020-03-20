// Fill out your copyright notice in the Description page of Project Settings.


#include "Spirit.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASpirit::ASpirit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

  // set up mesh
  this->Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
  this->RootComponent = Cast<USceneComponent>(this->Mesh);

  // insight starts out not collected
  this->beenCollected = false;

  // set interactable variables
  Super::Name = "Spirit";
  Super::Action = "collect insight";
}

// Called when the game starts or when spawned
void ASpirit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpirit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpirit::Interact_Implementation(APlayerController * Controller)
{
    Super::Interact_Implementation(Controller);

    // trigger update insight event
    this->beenCollected = true;
    TriggerUpdateInsight.Broadcast(this);
}

/*FString ASpirit::GetInteractText()
{
    if (this->beenCollected) {
        return FString::Printf(TEXT("%s: Press F to %s"), *Name, *Action);
    }

    return FString::Printf(TEXT("Insight already collected!"));
}*/


// Fill out your copyright notice in the Description page of Project Settings.


#include "VanishingDoor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AVanishingDoor::AVanishingDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

  // set up mesh
  this->Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
  this->RootComponent = this->Root;

  this->Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
  this->Mesh->SetupAttachment(Root);

  this->wasOpened = false;
}

// Called when the game starts or when spawned
void AVanishingDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVanishingDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


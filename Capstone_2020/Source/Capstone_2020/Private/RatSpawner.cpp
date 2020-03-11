// Fill out your copyright notice in the Description page of Project Settings.


#include "RatSpawner.h"

// Sets default values
ARatSpawner::ARatSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARatSpawner::BeginPlay()
{
	Super::BeginPlay();

  // test (please work or i'm gonna die)
	
}

// Called every frame
void ARatSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


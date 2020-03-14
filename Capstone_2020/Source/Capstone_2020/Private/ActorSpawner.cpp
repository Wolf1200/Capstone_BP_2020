// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorSpawner.h"
#include <cstdlib>
#include <ctime>
#include "Engine/World.h"
#include "GameFramework/Character.h"

// Sets default values
AActorSpawner::AActorSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

  this->Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
  this->RootComponent = this->Root;

  // set up radius visualization
  this->RadiusSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Spawn Radius"));
  this->RadiusSphere->SetGenerateOverlapEvents(false);
  this->RadiusSphere->SetSphereRadius(this->radius, false);
  this->RadiusSphere->SetupAttachment(this->RootComponent);
}

// Called when the game starts or when spawned
void AActorSpawner::BeginPlay()
{
	Super::BeginPlay();
	
  // spawn assigned actor
  SpawnActors();
}

// Called every frame
void AActorSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// spawns n actors
void AActorSpawner::SpawnActors()
{
    FVector origin = this->GetActorLocation();
    FRotator rotation = FRotator::ZeroRotator;

    srand(static_cast <unsigned> (time(0)));

    // give actors random rotation if rotation is true
    if (this->rotate) {
        rotation.Add(0.0, 0.0, static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
    }

    for (int i = 0; i < this->n; i++) {

        // spread actors out
       /* float x = rand() % static_cast <int> (this->radius * 2.0 + 1.0) + -this->radius;
        float y = rand() % static_cast <int> (this->radius * 2.0 + 1.0) + -this->radius;
        FVector loc = origin + FVector(x, y, 0.0f);*/

        ACharacter* newActor = GetWorld()->SpawnActor<ACharacter>(this->toSpawn, origin, rotation);
    }
}
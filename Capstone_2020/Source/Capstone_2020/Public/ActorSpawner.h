// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "ActorSpawner.generated.h"

UCLASS()
class CAPSTONE_2020_API AActorSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

  // so you can place the spawner in the world
  UPROPERTY()
    USceneComponent* Root;

  // displays spawn radius
  UPROPERTY(VisibleAnywhere)
    USphereComponent* RadiusSphere;

  // spawning variables
  UPROPERTY(EditAnywhere)
    UClass* toSpawn;      // actor class to spawn

  UPROPERTY(EditAnywhere)
    int n;                // number to spawn

  UPROPERTY(EditAnywhere)
    float radius;         // spawning radius

  UPROPERTY(EditAnywhere)
    bool rotate;          // if actors should be randomly rotated

  // spawns n number of given actor
  void SpawnActors();
};
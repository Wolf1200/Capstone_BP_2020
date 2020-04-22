// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VanishingDoor.generated.h"

UCLASS()
class CAPSTONE_2020_API AVanishingDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVanishingDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

  UPROPERTY()
      USceneComponent* Root;

  // door mesh
  UPROPERTY(BlueprintReadWrite, EditAnywhere)
      UStaticMeshComponent* Mesh;

  // insight required to vanish the door
  UPROPERTY(BlueprintReadWrite, EditAnywhere)
      float insightLvl;

  // door id
  UPROPERTY(BlueprintReadWrite)
      int doorID;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
      bool wasOpened;
};
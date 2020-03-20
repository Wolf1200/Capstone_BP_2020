// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Spirit.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInsightDelegate);

UCLASS()
class CAPSTONE_2020_API ASpirit : public AInteractable
{
    GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpirit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

  // insight update functions and event delegate
  void Interact_Implementation(APlayerController* Controller) override;

  //FString GetInteractText() override;

  UPROPERTY(BlueprintAssignable)
      FInsightDelegate TriggerUpdateInsight;

  // spirit mesh
  UPROPERTY(EditAnywhere)
      UStaticMeshComponent* Mesh;

  // if insight has been collected
  UPROPERTY(BlueprintReadOnly)
      bool beenCollected;
};

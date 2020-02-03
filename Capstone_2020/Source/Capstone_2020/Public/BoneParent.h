// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoneParent.generated.h"

UCLASS()
class CAPSTONE_2020_API ABoneParent : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ABoneParent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

  UPROPERTY()
  USceneComponent* Root;

  UPROPERTY(EditAnywhere)
  UStaticMeshComponent* Mesh;

  UPROPERTY(EditAnywhere)
  UBoxComponent* BoxCollider;

  UFUNCTION()
  void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
       UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
       const FHitResult& SweepResult);
};
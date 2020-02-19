// Fill out your copyright notice in the Description page of Project Settings.


#include "BoneParent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABoneParent::ABoneParent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
  RootComponent = Root;

  Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
 // Mesh->AttachTo(Root); (deprecated)
 // Mesh->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetIncludingScale); (Use SetupAttachement)
  Mesh->SetupAttachment(Root);

  this->BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
  this->BoxCollider->SetGenerateOverlapEvents(true);
  this->BoxCollider->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
  this->BoxCollider->SetupAttachment(this->RootComponent);
  // this->BoxCollider->AttachToComponent(this->RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
}

// Called when the game starts or when spawned
void ABoneParent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoneParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
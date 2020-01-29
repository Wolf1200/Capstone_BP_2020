// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlatformFilemanager.h"
#include "Misc/Paths.h"
#include "TextReaderComponent.generated.h"


UCLASS( Blueprintable, meta=(BlueprintSpawnableComponent) )
class CAPSTONE_BP_2020_API UTextReaderComponent : public UActorComponent
{
	GENERATED_BODY()

      UFUNCTION(BlueprintCallable)
      FString ReadFile(FString filename);

public:	
	// Sets default values for this component's properties
	UTextReaderComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};

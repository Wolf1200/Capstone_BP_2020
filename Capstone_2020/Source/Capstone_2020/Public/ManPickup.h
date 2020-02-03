#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "ManPickup.generated.h"

UCLASS()
class CAPSTONE_2020_API AManPickup : public AInteractable
{
	GENERATED_BODY()

public:
	AManPickup();

	void Interact_Implementation(APlayerController* Controller) override;

protected:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ItemID;
};
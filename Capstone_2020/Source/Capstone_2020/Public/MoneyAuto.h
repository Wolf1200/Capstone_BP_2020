#pragma once

#include "CoreMinimal.h"
#include "AutoPickup.h"
#include "MoneyAuto.generated.h"

UCLASS()
class CAPSTONE_2020_API AMoneyAuto : public AAutoPickup
{
	GENERATED_BODY()

public:
	AMoneyAuto();

	void Collect_Implementation(APlayerController* Controller) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Value;
};
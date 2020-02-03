#include "MoneyAuto.h"
#include "Capstone_2020Controller.h"

AMoneyAuto::AMoneyAuto()
{
	Super::ItemID = FName("money");
	Value = 1;
}

void AMoneyAuto::Collect_Implementation(APlayerController* Controller)
{
	ACapstone_2020Controller* IController = Cast<ACapstone_2020Controller>(Controller);
	IController->Money += Value;
	Destroy();
}
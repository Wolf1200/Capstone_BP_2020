#include "MoneyAutoPickup.h"
#include "Capstone_2020Controller.h"

AMoneyAutoPickup::AMoneyAutoPickup()
{
	ItemID = FName("money");
	Value = 1;
}

void AMoneyAutoPickup::Collect_Implementation(APlayerController* Controller)
{
	ACapstone_2020Controller* IController = Cast<ACapstone_2020Controller>(Controller);
	IController->Money += Value;
	Destroy();
}
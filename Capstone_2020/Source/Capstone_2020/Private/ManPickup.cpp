#include "ManPickup.h"
#include "Capstone_2020Controller.h"

AManPickup::AManPickup()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
	RootComponent = Cast<USceneComponent>(PickupMesh);

	ItemID = FName("No ID");

	Super::Name = "Item";
	Super::Action = "pickup";
}

void AManPickup::Interact_Implementation(APlayerController* Controller)
{
	Super::Interact_Implementation(Controller);

	ACapstone_2020Controller* IController = Cast<ACapstone_2020Controller>(Controller);
	if (IController->AddItemToInventoryByID(ItemID))
		Destroy();
}
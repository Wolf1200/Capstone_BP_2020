// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Capstone_2020Character.h"
#include "Interactable.h"
#include "AutoPickup.h"
#include "InventoryItem.h"
#include "Capstone_2020Controller.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

//////////////////////////////////////////////////////////////////////////
// ACapstone_2020Character

ACapstone_2020Character::ACapstone_2020Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 400.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

  DefaultInsight = 0;
  Insight = DefaultInsight;

  // Create the collection sphere
  CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
  CollectionSphere->SetupAttachment(RootComponent);
  CollectionSphere->SetSphereRadius(200.f);

  SprintSpeedMultiplier = 1.8f;

  // set dash multiplier
  this->DashMultiplier = 30;
  this->LastDash = LastDash.Now();

  // set targeting
  this->isTargeting = false;

  // set height (based on mesh lol)
  this->PlayerHeight = 165.0f;
}

//////////////////////////////////////////////////////////////////////////
// Input

void ACapstone_2020Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACapstone_2020Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACapstone_2020Character::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ACapstone_2020Character::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ACapstone_2020Character::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ACapstone_2020Character::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ACapstone_2020Character::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ACapstone_2020Character::OnResetVR);

    // Sprint functionality
    PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ACapstone_2020Character::Sprint);
    PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ACapstone_2020Character::StopSprinting);

    // Dash functionality
    PlayerInputComponent->BindAction("Dash", IE_Pressed, this, &ACapstone_2020Character::Dash);
}


void ACapstone_2020Character::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ACapstone_2020Character::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void ACapstone_2020Character::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void ACapstone_2020Character::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ACapstone_2020Character::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ACapstone_2020Character::MoveForward(float Value)
{
    if ((Controller != NULL) && (Value != 0.0f)) {

        // find out which way is forward
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // get forward vector
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);        
    }
}

void ACapstone_2020Character::MoveRight(float Value)
{
    if ((Controller != NULL) && (Value != 0.0f))
    {
        // find out which way is right
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // get right vector 
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        // add movement in that direction
        AddMovementInput(Direction, Value);    
    }
}

void ACapstone_2020Character::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	CollectAutoPickups();
	CheckForInteractables();
}

void ACapstone_2020Character::CollectAutoPickups()
{
	// Get all overlapping Actors and store them in an array
	TArray<AActor*> CollectedActors;
	CollectionSphere->GetOverlappingActors(CollectedActors);

	ACapstone_2020Controller* IController = Cast<ACapstone_2020Controller>(GetController());

	// For each collected Actor
	for (int32 iCollected = 0; iCollected < CollectedActors.Num(); ++iCollected)
	{
		// Cast the actor to AAutoPickup
		AAutoPickup* const TestPickup = Cast<AAutoPickup>(CollectedActors[iCollected]);
		// If the cast is successful and the pickup is valid and active 
		if (TestPickup && !TestPickup->IsPendingKill())
		{
			TestPickup->Collect(IController);
		}
	}
}

void ACapstone_2020Character::CheckForInteractables()
{
	// Create a LineTrace to check for a hit
	FHitResult HitResult;

	int32 Range = 400;
  FVector StartTrace = this->GetActorLocation();
  FVector EndTrace =  Range * StartTrace;

  // shape of sight (sphere)
  FCollisionShape TraceShape = FCollisionShape::MakeSphere(48.0f);

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	ACapstone_2020Controller* IController = Cast<ACapstone_2020Controller>(GetController());

	if (IController)
	{
		// Check if something is hit
		if (GetWorld()->SweepSingleByChannel(HitResult, StartTrace, EndTrace, FRotator(0.0f, 0.0f, 0.0f).Quaternion(), ECC_Visibility, TraceShape, QueryParams))
		{
			// Cast the actor to AInteractable
			AInteractable* Interactable = Cast<AInteractable>(HitResult.GetActor());
			// If the cast is successful
			if (Interactable)
			{
				IController->CurrentInteractable = Interactable;
				return;
			}
		}

		IController->CurrentInteractable = nullptr;
	}
}

void ACapstone_2020Character::Sprint() {
    GetCharacterMovement()->MaxWalkSpeed *= SprintSpeedMultiplier;
}

void ACapstone_2020Character::StopSprinting() {
    GetCharacterMovement()->MaxWalkSpeed /= SprintSpeedMultiplier;
}

void ACapstone_2020Character::Dash() {
    if (GetCharacterMovement()->Velocity.X != 0 && GetCharacterMovement()->Velocity.Y != 0 && !GetCharacterMovement()->IsFalling() && (LastDash.Now() - LastDash).GetSeconds() > .4) {
        LastDash = LastDash.Now();
        GetCharacterMovement()->Velocity.Z = 1000;
        GetCharacterMovement()->Velocity.X *= this->DashMultiplier;
        GetCharacterMovement()->Velocity.Y *= this->DashMultiplier;
    }
}
#include "RPGPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "RPGPlayerCharacter.h"

void ARPGPlayerController::BeginPlay()
{
	Super::BeginPlay();
	mpPlayerCharacter = Cast<ARPGPlayerCharacter>(GetCharacter());
	
}

void ARPGPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ARPGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputLocalPlayerSubsystem* EInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	EInputSubsystem->ClearAllMappings();
	EInputSubsystem->AddMappingContext(mpInputContext, 0);

	UEnchancedInputComponent* EInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	EInputComponent->BindAction(mpInputData->InputMove, ETriggerEvent::Triggered, this, &ARPGPlayerCharacter::MoveCallback);
}

void ARPGPlayerController::OnSetDestinationPressed(const FInputActionValue& aValue)
{
}

void ARPGPlayerController::OnSetDestinationReleased(const FInputActionValue& aValue)
{
}

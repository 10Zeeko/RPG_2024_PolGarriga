#include "RPGPlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

ARPGPlayerCharacter::ARPGPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = bUseControllerRotationRoll = bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = {0.0f, 600.0f, 0.0f};
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
	mpCameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	mpCameraBoom->SetupAttachment(RootComponent);
	mpCameraBoom->SetUsingAbsoluteRotation(true);
	mpCameraBoom->TargetArmLength = 800.0f;
	mpCameraBoom->SetRelativeRotation({-60.0f, 0.0f, 0.0f});
	mpCameraBoom->bDoCollisionTest = false;

	mpTopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	mpTopDownCameraComponent->SetupAttachment(mpCameraBoom, USpringArmComponent::SocketName);
	mpTopDownCameraComponent->bUsePawnControlRotation = false;
}

void ARPGPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARPGPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


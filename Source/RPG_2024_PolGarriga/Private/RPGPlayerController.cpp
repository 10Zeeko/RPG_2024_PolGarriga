#include "RPGPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputConfigData.h"
#include "RPGPlayerCharacter.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraFunctionLibrary.h"
#include "RPG_2024_PolGarriga/Public/Utils.h"

void ARPGPlayerController::BeginPlay()
{
	Super::BeginPlay();
	mpPlayerCharacter = Cast<ARPGPlayerCharacter>(GetCharacter());
	bShowMouseCursor = true;
	
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

	UEnhancedInputComponent* EInputComponent {Cast<UEnhancedInputComponent>(InputComponent)};
	EInputComponent->BindAction(mpInputData->mpInputMove, ETriggerEvent::Triggered, this, &ARPGPlayerController::OnSetDestinationPressed);
	EInputComponent->BindAction(mpInputData->mpInputMove, ETriggerEvent::Completed, this, &ARPGPlayerController::OnSetDestinationReleased);
	EInputComponent->BindAction(mpInputData->mpInputAct, ETriggerEvent::Completed, this, &ARPGPlayerController::OnActPressed);

	for (int ButtonIndex {0}; ButtonIndex < mpInputData->mpInputSkills.Num(); ButtonIndex++)
	{
		EInputComponent->BindAction(mpInputData->mpInputSkills[ButtonIndex], ETriggerEvent::Completed, this, &ARPGPlayerController::OnSkillPressed, ButtonIndex);
	}
}

void ARPGPlayerController::OnSetDestinationPressed(const FInputActionValue& aValue)
{
	mSetDestination = true;
}

void ARPGPlayerController::OnSetDestinationReleased(const FInputActionValue& aValue)
{
	mSetDestination = false;

	if (mFollowTime <= mThresholdPress)
	{
		FVector HitLocation {FVector::ZeroVector};
		GetHitResultUnderCursor(ECC_Visibility, true, mHitResult);
		HitLocation = mHitResult.Location;

		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, HitLocation);
		if (mpFXCursor)
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, mpFXCursor, HitLocation, FRotator::ZeroRotator, FVector{1.0f}, true, true, ENCPoolMethod::None, true);
		}
	}
}

void ARPGPlayerController::OnSkillPressed(int aButtonPressed)
{
	if (auto SkillPressed {mSkills[aButtonPressed]}; SkillPressed != ESkill::NONE)
	{
		if (auto* Skill{GetSkill(SkillPressed)}; Skill)
		{
			ScreenD(Format1("Skill: %s", *Skill->Description));
			mSkillSelected = *Skill;
		}
	}
}

void ARPGPlayerController::OnActPressed(const FInputActionValue& aValue)
{
	if (mSkillSelected.Name == ESkill::NONE) return;
	FVector HitLocation {FVector::ZeroVector};
	GetHitResultUnderCursorByChannel(TraceTypeQuery1, true, mHitResult);

	evOnLocationClick.Broadcast(mHitResult.Location, mSkillSelected);
}

FSkillDataRow* ARPGPlayerController::GetSkill(ESkill aSkill)
{
	FSkillDataRow* SkillFound {};

	if (mSkillDB)
	{
		FName SkillString {UEnum::GetDisplayValueAsText(aSkill).ToString()};
		static const FString FindContext {FString("Searching for ").Append(SkillString.ToString())};
		SkillFound = mSkillDB->FindRow<FSkillDataRow>(SkillString, FindContext, true);
	}
	
	return SkillFound;
}

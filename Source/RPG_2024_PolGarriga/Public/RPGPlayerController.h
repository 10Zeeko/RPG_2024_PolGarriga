// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPGPlayerController.h"
#include "GameFramework/PlayerController.h"
#include "RPGPlayerController.generated.h"

class ARPGPlayerCharacter;
class UInputConfigData;
class UInputMappingContext;
class UNiagaraSystem;
struct FInputActionValue;

UCLASS()
class RPG_2024_POLGARRIGA_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ARPGPlayerCharacter* mpPlayerCharacter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=mInputs)
	UInputMappingContext* mpInputData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=mInputs)
	UNiagaraSystem* mpFXCursor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float mThresholdPress;

protected:
	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	void OnSetDestinationPressed(const FInputActionValue& aValue);
	void OnSetDestinationReleased(const FInputActionValue& aValue);

private:
	FHitResult mHitResult {};
	bool mSetDestination {false};
	float mFollowTime {0.0f};
};

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "SkillDataRow.h"
#include "GameFramework/PlayerController.h"
#include "RPGPlayerController.generated.h"

struct FSkillDataRow;
class ARPGPlayerCharacter;
class UInputConfigData;
class UInputMappingContext;
class UNiagaraSystem;
struct FInputActionValue;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLocationClick, FVector, aClickLocation, const FSkillDataRow&, aSkillData);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDirectionSkillCast, FRotator, aRotation, FSkillDataRow, aSkillData);

UCLASS()
class RPG_2024_POLGARRIGA_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ARPGPlayerCharacter* mpPlayerCharacter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=mInputs)
	UInputMappingContext* mpInputContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=mInputs)
	UInputConfigData* mpInputData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UNiagaraSystem* mpFXCursor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float mThresholdPress;

#pragma region SKILLS
	FSkillDataRow* GetSkill(ESkill skill);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=mSKILL)
	TArray<TEnumAsByte<ESkill>> mSkills;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=mSKILL)
	UDataTable* mSkillDB;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=mSKILL)
	FSkillDataRow mSkillSelected;
	
#pragma endregion

#pragma region EVENTS
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnLocationClick evOnLocationClick;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnDirectionSkillCast evOnDirectionSkillCast;

#pragma endregion
protected:
	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	void OnSetDestinationPressed(const FInputActionValue& aValue);
	void OnSetDestinationReleased(const FInputActionValue& aValue);

	void OnSkillPressed(int aButtonPressed);
	void OnActPressed(const FInputActionValue& aValue);
private:
	FHitResult mHitResult {};
	bool mSetDestination {false};
	float mFollowTime {0.0f};
};

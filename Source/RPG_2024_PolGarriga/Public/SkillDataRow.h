#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Templates/SubclassOf.h"
#include "SkillDataRow.generated.h"

class ASkillBase;
UENUM(BlueprintType)
enum class ESkill : uint8
{
	NONE = 0 UMETA(DisplayName = "None"),
	FIREBALL UMETA(DisplayName = "Fireball"),
	LIGHT UMETA(DisplayName = "Light"),
	HEAL UMETA(DisplayName = "Heal"),
	SMOKE UMETA(DisplayName = "Smoke")
};

USTRUCT(Blueprintable, BlueprintType)
struct FSkillDataRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESkill Name {ESkill::NONE};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TWeakObjectPtr<UTexture2D> Image {nullptr};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ASkillBase> SkillBP {nullptr};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Scale {1.0f};
	
};

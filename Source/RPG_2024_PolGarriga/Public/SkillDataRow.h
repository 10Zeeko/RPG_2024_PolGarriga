#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Templates/SubclassOf.h"
#include "SkillDataRow.generated.h"

class ASkillBase;
UENUM(BlueprintType)
enum ESkill
{
	NONE = 0,
	FIREBALL
};

USTRUCT(Blueprintable, BlueprintType)
struct FSkillDataRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<ESkill> Name {ESkill::NONE};
	
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

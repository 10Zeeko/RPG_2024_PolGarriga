#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Templates/SubclassOf.h"
#include "StatsDataRow.generated.h"

class AStatsBase;

UENUM(BlueprintType)
enum class EStat
{
	NONE = 0 UMETA(DisplayName = "None"),
	TANK UMETA(DisplayName = "Tank"),
	KNIGHT UMETA(DisplayName = "Knight"),
	MAGE UMETA(DisplayName = "Mage")
};

USTRUCT(Blueprintable, BlueprintType)
struct FStatsDataRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EStat Name {EStat::NONE};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mHP {0.0f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mDamage {0.0f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mMagicDamage {0.0f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mAttackSpeed {0.0f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mHabilitySpeed {0.0f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mDefense {0.0f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mSpeed {0.0f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Scale {1.0f};
};

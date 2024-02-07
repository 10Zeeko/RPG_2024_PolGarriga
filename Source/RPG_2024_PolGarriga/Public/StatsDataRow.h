#pragma once


enum ESkill
{
	NONE = 0,
	TANK,
	KNIGHT,
	MAGE
};

UCLASS()
class StatsDataRow
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<ESkill> Name {ESkill::NONE};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mHP {0.0f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mDamage {0.0f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mSpeed {0.0f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Scale {1.0f};
};

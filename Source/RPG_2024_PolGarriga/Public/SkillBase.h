// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkillBase.generated.h"

UCLASS()
class RPG_2024_POLGARRIGA_API ASkillBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkillBase();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(ExposeOnSpawn=true))
	AActor* mpTarget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(ExposeOnSpawn=true))
	float mDamage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(ExposeOnSpawn=true))
	float mDuration;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};

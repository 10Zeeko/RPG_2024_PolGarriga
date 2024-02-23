// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyWaveSpawner.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSpawnedEnemy);

UCLASS()
class RPG_2024_POLGARRIGA_API AEnemyWaveSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	AEnemyWaveSpawner();
	UPROPERTY(EditAnywhere)
	TArray<FTransform> mSpawnTransform;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> mEnemyBP;

	int mCurrentWave {1};
	int mSpawnColdown {1};

	FTimerHandle mWaveHandler;
	FTimerHandle mSpawnHandler;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FSpawnedEnemy EnemySpawned;

	void SpawnEnemy();

	void SpawnWave();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

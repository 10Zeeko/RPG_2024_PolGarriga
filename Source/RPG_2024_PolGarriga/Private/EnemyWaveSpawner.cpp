// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyWaveSpawner.h"

// Sets default values
AEnemyWaveSpawner::AEnemyWaveSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AEnemyWaveSpawner::SpawnEnemy()
{
	FTransform SpawnTransform = mSpawnTransform[FMath::RandRange(0, mSpawnTransform.Num() - 1)];
	GetWorld()->SpawnActor<AActor>(mEnemyBP, SpawnTransform);
	EnemySpawned.Broadcast();
}

void AEnemyWaveSpawner::SpawnWave()
{
	// Decides the quantity of enemies to spawn depending on the wave number
	int NumEnemiesToSpawn = mCurrentWave * 1.5f;
	// Calls the spawn enemy function for each enemy with a delay
	for (int i = 0; i < NumEnemiesToSpawn; i++)
	{
		GetWorld()->GetTimerManager().SetTimer(mSpawnHandler, this, &AEnemyWaveSpawner::SpawnEnemy, mSpawnColdown, false);
	}
	
	mCurrentWave++;
}

// Called when the game starts or when spawned
void AEnemyWaveSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnWave();
	GetWorld()->GetTimerManager().SetTimer(mWaveHandler, this, &AEnemyWaveSpawner::SpawnWave, 30.0f, true);
}

// Called every frame
void AEnemyWaveSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


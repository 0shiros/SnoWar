// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Engine/Engine.h"
#include "Engine/World.h"

// Sets default values
ATower::ATower()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
	timeBetweenShots = 60.0f / fireRate;
	
}

bool ATower::CanFire(float deltaTime)
{
	timeElapsed += deltaTime;
	
	if (timeElapsed >= timeBetweenShots)	
	{
		timeElapsed -= timeBetweenShots;
		return true;
	}
	return false;
}

void ATower::CreateProjectile()
{
	if (UWorld* World = GetWorld())
	{
		FVector SpawnLocation = projectileSpawnPosition;
		FRotator SpawnRotation = GetActorRotation();
		AProjectile* projectile = World->SpawnActor<AProjectile>(projectileClass, SpawnLocation, SpawnRotation);
		if (projectile)
		{
			projectile->SetDamage(projectileDamage);
			projectile->SetSpeed(projectileSpeed);
		}
	}
}

void ATower::Buy()
{
}

void ATower::Sell()
{
}

void ATower::DetectEnemiesInRange()
{
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CanFire(DeltaTime))
	{
		CreateProjectile();
	}

}

// Called to bind functionality to input
void ATower::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


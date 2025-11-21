// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "GameFramework/Pawn.h"
#include "Projectile.h"
#include "Tower.generated.h"


UCLASS()
class SNOWAR_API ATower : public APawn
{
	GENERATED_BODY()
	
public:
	// Sets default values for this pawn's properties
	ATower();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Price")
	int priceBuy = 50;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Price")
	int priceSell = 25;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	TArray<AEnemy*> EnemiesInRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	AEnemy* EnemyTarget;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	TSubclassOf<AProjectile> projectileClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	FVector projectileSpawnPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	FRotator projectileSpawnRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float fireRate = 30.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float range = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	int projectileDamage = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float projectileSpeed = 1000.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float timeBetweenShots = 0.0f;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float timeElapsed = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float rotationSpeed = 5.0f;

	UFUNCTION(BlueprintCallable, Category = "Turret")
	bool CanFire(float deltaTime);
	UFUNCTION(BlueprintCallable, Category = "Turret")
	void CreateProjectile();
	UFUNCTION(BlueprintCallable, Category = "Turret")
	void Buy();
	UFUNCTION(BlueprintCallable, Category = "Turret")
	void Sell();
	UFUNCTION(BlueprintCallable, Category = "Turret")
	void DetectEnemiesInRange();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class SNOWAR_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Characteristics")
	int health = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Characteristics")
	int speed = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Characteristics")
	int damage = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Characteristics")
	int floconsDrop = 5;

public:
	UFUNCTION(BlueprintCallable)
	void TakeDamage(int damageAmount);
	UFUNCTION(BlueprintCallable)
	void Die();
};

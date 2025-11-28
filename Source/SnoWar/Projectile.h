// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class SNOWAR_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadOnly, Category = "Attack")
	float speed = 1000.0f;
	UPROPERTY(BlueprintReadOnly, Category = "Attack")
	int damage = 10;
	UPROPERTY(BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* mesh;
	UPROPERTY(BlueprintReadWrite, Category = "Enemies")
	AEnemy* targetEnemy;

public:	

	void SetSpeed(float newSpeed);
	void SetDamage(int newDamage);
	void SetTargetEnemy(AEnemy* enemy);
};

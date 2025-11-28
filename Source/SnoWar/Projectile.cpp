#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AProjectile::SetSpeed(float newSpeed)
{
	speed = newSpeed;
}

void AProjectile::SetDamage(int newDamage)
{
	damage = newDamage;
}

void AProjectile::SetTargetEnemy(AEnemy* enemy)
{
	targetEnemy = enemy;
}


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

	mesh = FindComponentByClass<UStaticMeshComponent>();
	
	if (mesh)
	{
		mesh->SetSimulatePhysics(true);	
		mesh->SetEnableGravity(false);
		ApplyInitialVelocity();
	}

}

void AProjectile::SetSpeed(float newSpeed)
{
	speed = newSpeed;
}

void AProjectile::SetDamage(int newDamage)
{
	damage = newDamage;
}

void AProjectile::ApplyInitialVelocity()
{
	FVector linearVelocity = GetActorForwardVector() * speed;
	mesh ->SetPhysicsLinearVelocity(linearVelocity);
}


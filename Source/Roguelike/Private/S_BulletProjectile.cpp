// Fill out your copyright notice in the Description page of Project Settings.


#include "S_BulletProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AS_BulletProjectile::AS_BulletProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Spherecomp = CreateDefaultSubobject<USphereComponent>("Spherecomp");
	RootComponent = Spherecomp;

	ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>("ParticleComp");
	ParticleComp->SetupAttachment(Spherecomp);

	//projectile(bullet) basic property
	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = 1000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bInitialVelocityInLocalSpace = true;

}

// Called when the game starts or when spawned
void AS_BulletProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AS_BulletProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "S_Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;

UCLASS()
class ROGUELIKE_API AS_Projectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AS_Projectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere);
	USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere); 
	UProjectileMovementComponent* MovementComp;

	UPROPERTY(VisibleAnywhere);
	UParticleSystemComponent* ParticleComp;

	//override beginplay when game starts
	/*virtual void BeginPlay() override;*/


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "S_Character.generated.h"

// added new class
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ROGUELIKE_API AS_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AS_Character();

protected:

	//default springArm
	UPROPERTY(VisibleAnywhere);
	USpringArmComponent* SpringArmComp;

	//default camera
	UPROPERTY(VisibleAnywhere);
	UCameraComponent* CameraComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//player movement function
	void moveForward(float value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

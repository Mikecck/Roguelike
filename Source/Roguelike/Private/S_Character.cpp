// Fill out your copyright notice in the Description page of Project Settings.


#include "S_Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AS_Character::AS_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//create springArm
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);

	//create local view camera
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	//contorl input disable on Yaw, the charater's facing direction then wont be changed by controller 
	bUseControllerRotationYaw = false;

	//
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

// Called when the game starts or when spawned
void AS_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AS_Character::moveForward(float value)
{
	//player forward movement follows the direction of controller
	FRotator ControlRo = GetControlRotation();
	ControlRo.Pitch = 0.0f;
	ControlRo.Roll = 0.0f;

	AddMovementInput(ControlRo.Vector(), value);
}

void AS_Character::moveRight(float value)
{
	FRotator ControlRo = GetControlRotation();
	ControlRo.Pitch = 0.0f;
	ControlRo.Roll = 0.0f;

	//Y vector method from engine code
	FVector RightVector = FRotationMatrix(ControlRo).GetScaledAxis(EAxis::Y);

	AddMovementInput(RightVector, value);
}


void AS_Character::normalShoot()
{
	FTransform SpawnTM = FTransform(GetControlRotation(), GetActorLocation());

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParams);
}


// Called every frame
void AS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//player movement
	PlayerInputComponent->BindAxis("moveForward", this, &AS_Character::moveForward);
	PlayerInputComponent->BindAxis("moveRight", this, &AS_Character::moveRight);
	//Spawn component
	PlayerInputComponent->BindAxis("turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("lookUp", this, &APawn::AddControllerPitchInput);
	//Shoting component
	PlayerInputComponent->BindAction("normalShoot", IE_Pressed, this, &AS_Character::normalShoot);
}


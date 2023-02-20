// Fill out your copyright notice in the Description page of Project Settings.


#include "Character2.h"
#include <GameFramework/SpringArmComponent.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <Camera/CameraComponent.h>

// Sets default values
ACharacter2::ACharacter2()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

void ACharacter2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ACharacter2::AttaclButtomPressed);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACharacter2::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACharacter2::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ACharacter2::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &ACharacter2::Turn);
}

// Called when the game starts or when spawned
void ACharacter2::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacter2::AttaclButtomPressed()
{
}

void ACharacter2::MoveForward(float Value)
{
	const FRotator ControlRotation = Controller->GetControlRotation();
	const FRotator YawRotation = FRotator(0.f, ControlRotation.Yaw, 0.f);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void ACharacter2::MoveRight(float Value)
{
	const FRotator ControlRotation = Controller->GetControlRotation();
	const FRotator YawRotation = FRotator(0.f, ControlRotation.Yaw, 0.f);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void ACharacter2::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ACharacter2::Turn(float Value)
{
	AddControllerYawInput(Value);
}

// Called every frame
void ACharacter2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




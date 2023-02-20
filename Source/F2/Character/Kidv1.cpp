// Fill out your copyright notice in the Description page of Project Settings.


#include "Kidv1.h"
#include <GameFramework/SpringArmComponent.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <Camera/CameraComponent.h>

// Sets default values
AKidv1::AKidv1()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom -> SetupAttachment(RootComponent);
	CameraBoom -> TargetArmLength = 200.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;


}

// Called to bind functionality to input
void AKidv1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AKidv1::AttacklButtomPressed);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AKidv1::SprintlButtomPressed);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AKidv1::SprintlButtomReleased);

	PlayerInputComponent->BindAxis("MoveForward", this, &AKidv1::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AKidv1::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AKidv1::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &AKidv1::Turn);
}

// Called when the game starts or when spawned
void AKidv1::BeginPlay()
{
	Super::BeginPlay();
	SpeedMode = ESpeedMode::ESM_Jog;
	GetCharacterMovement()->MaxWalkSpeed = JogSpeed;
	
}

void AKidv1::AttacklButtomPressed()
{
}

void AKidv1::SprintlButtomPressed()
{
	SpeedMode = ESpeedMode::ESM_Sprint;
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void AKidv1::SprintlButtomReleased()
{
	SpeedMode = ESpeedMode::ESM_Jog;
	GetCharacterMovement()->MaxWalkSpeed = JogSpeed;
}

void AKidv1::MoveForward(float Value)
{
	const FRotator ControlRotation = Controller->GetControlRotation();
	const FRotator YawRotation = FRotator(0.f, ControlRotation.Yaw, 0.f);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AKidv1::MoveRight(float Value)
{
	const FRotator ControlRotation = Controller->GetControlRotation();
	const FRotator YawRotation = FRotator(0.f, ControlRotation.Yaw, 0.f);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AKidv1::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AKidv1::Turn(float Value)
{
	AddControllerYawInput(Value);
}

// Called every frame
void AKidv1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



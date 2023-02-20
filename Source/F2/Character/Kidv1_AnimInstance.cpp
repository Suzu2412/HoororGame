// Fill out your copyright notice in the Description page of Project Settings.

#include "Kidv1_AnimInstance.h"
#include "GameFramework/Character.h"
#include <GameFramework/CharacterMovementComponent.h>


void UKidv1_AnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	Character = Cast<ACharacter>(TryGetPawnOwner());
}

void UKidv1_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (Character == nullptr)
	{
		Character = Cast<ACharacter>(TryGetPawnOwner());
	}
	if (Character == nullptr)
	{
		return;
	}
	Velocity = Character->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsAccelerating = Character->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f;
	bIsAir = Character->GetCharacterMovement()->IsFalling();
}

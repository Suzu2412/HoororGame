// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Kidv1_AnimInstance.generated.h"

/**
 * 
 */
class ACharacter;
UCLASS()
class F2_API UKidv1_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
private:
	UPROPERTY(BlueprintReadOnly, meta =(AllowPrivateAccess = "true"), Category = Character)
	ACharacter* Character = nullptr;

	UPROPERTY()
	FVector Velocity;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = Character)
	float Speed;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = Character)
	bool bIsAir;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = Character)
	bool bIsAccelerating;
};

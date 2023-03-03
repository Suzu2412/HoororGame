// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "F2/Types/SpeedMode.h"
#include "F2/Interface/Attackableinterface.h"
#include "Kidv1.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UAttackComponent;

UCLASS()
class F2_API AKidv1 : public ACharacter, public IAttackableinterface
{
	GENERATED_BODY()

public:

	AKidv1();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PostInitializeComponents() override;

	UAttackComponent* GetAttack_Implementation() const;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	virtual void AttacklButtomPressed();
	virtual void SprintlButtomPressed();
	virtual void SprintlButtomReleased();
	virtual void MoveForward(float Value);
	virtual void MoveRight(float Value);
	virtual void LookUp(float Value);
	virtual void Turn(float Value);

private:
	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* FollowCamera;

	UPROPERTY()
	ESpeedMode SpeedMode;

	UPROPERTY(EditAnywhere, Category = Movement)
	float SprintSpeed = 900.f;
	UPROPERTY(EditAnywhere, Category = Movement)
	float JogSpeed = 500.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	UAttackComponent* AttackComponent;

	//setter va getter
public:	

	FORCEINLINE UFUNCTION(BlueprintCallable) UAttackComponent* GetAttackComponent() const { return AttackComponent; }
};

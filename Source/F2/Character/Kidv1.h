// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "F2/Types/SpeedMode.h"
#include "Kidv1.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class F2_API AKidv1 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AKidv1();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

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


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void AttacklButtomPressed();
	virtual void SprintlButtomPressed();
	virtual void SprintlButtomReleased();
	virtual void MoveForward(float Value);
	virtual void MoveRight(float Value);
	virtual void LookUp(float Value);
	virtual void Turn(float Value);

public:	
	
};

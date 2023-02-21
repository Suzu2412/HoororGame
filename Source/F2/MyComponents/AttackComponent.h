// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "F2/Types/AttackState.h"
#include "AttackComponent.generated.h"

class UAnimMontage;
class ACharacter;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class F2_API UAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttackComponent();

	UFUNCTION(BlueprintCallable)
	void RequestAttack();

	void PlayAnimMontage(UAnimMontage* MontageToPlay);
	UFUNCTION(BlueprintCallable)
	void ResetAttack();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void Attack();

private:
	UPROPERTY()
	EAttackState AttackState;

	UPROPERTY(EditAnywhere, Category = Animation)
	TArray<UAnimMontage*> AttackAnimMontages;

	UPROPERTY()
	ACharacter* Character;
public:	

	FORCEINLINE void SetCharacter(ACharacter* Value) { Character = Value; }

		
};

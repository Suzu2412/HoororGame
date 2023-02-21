// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackComponent.h"
#include "GameFramework/Character.h"
#include "Animation/AnimInstance.h"

// Sets default values for this component's properties
UAttackComponent::UAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UAttackComponent::RequestAttack()
{
	if (AttackState == EAttackState::ECS_Free && AttackAnimMontages.IsEmpty()==false)
	{
		Attack();
	}
}



// Called when the game starts
void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();
	AttackState = EAttackState::ECS_Free;
	// ...
	
}

void UAttackComponent::Attack()
{
	UAnimMontage* MontageToPlay = AttackAnimMontages[0];
	if (MontageToPlay) 
	{
		PlayAnimMontage(MontageToPlay);
		AttackState = EAttackState::ECS_Attack;
	}

}

void UAttackComponent::PlayAnimMontage(UAnimMontage* MontageToPlay)
{
	if (Character == nullptr)
	{
		return;
	}
	UAnimInstance* AnimInstance = Character->GetMesh()->GetAnimInstance();
	if (AnimInstance && MontageToPlay)
	{
		AnimInstance->Montage_Play(MontageToPlay);
	}
}

void UAttackComponent::ResetAttack()
{
	AttackState = EAttackState::ECS_Free;
}



// Called every frame
// void UAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
//}

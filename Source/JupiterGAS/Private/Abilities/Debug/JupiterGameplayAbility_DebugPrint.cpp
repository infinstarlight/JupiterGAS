// Fill out your copyright notice in the Description page of Project Settings

#include "Abilities/Debug/JupiterGameplayAbility_DebugPrint.h"

void UJupiterGameplayAbility_DebugPrint::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, DebugString);
}

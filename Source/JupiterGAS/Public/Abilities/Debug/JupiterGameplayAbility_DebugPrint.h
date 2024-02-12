// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Abilities/JupiterGameplayAbility.h"
#include "JupiterGameplayAbility_DebugPrint.generated.h"

/**
 * 
 */
UCLASS()
class JUPITERGAS_API UJupiterGameplayAbility_DebugPrint : public UJupiterGameplayAbility
{
	GENERATED_BODY()

public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                             const FGameplayAbilityActivationInfo ActivationInfo,
	                             const FGameplayEventData* TriggerEventData) override;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Debug")
	FString DebugString = "Hello World! This is Jupiter GAS!";
};

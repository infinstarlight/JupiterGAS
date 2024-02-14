// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/JupiterGameplayAbility.h"
#include "JupiterGameplayAbility_Trace.generated.h"

/**
 * @brief Base class for all trace abilities
 *
 * 
 */
UCLASS()
class JUPITERGAS_API UJupiterGameplayAbility_Trace : public UJupiterGameplayAbility
{
	GENERATED_BODY()

public:

	//The type of trace to use
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Ability|Trace")
	EAbilityTraceType TraceType;

	//Should the trace use complex collision
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Ability|Trace")
	bool bShouldTraceComplex = false;

	//The modifer to apply to the end location of the trace
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Ability|Trace")
	float TraceDistance = 1000.0f;

	//Debug color to use when drawing the trace
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Ability|Trace")
	FColor DebugColor = FColor::Red;

	//Should the drawn trace persist
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Ability|Trace")
	bool bAllowPersistantDebug = false;

	//Array of actors to ignore when tracing
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Ability|Trace")
	TArray<AActor*> ActorsToIgnore;

	//The Start location of the trace
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Ability|Trace")
	FVector TraceStartLocation;

	//The End location of the trace
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Ability|Trace")
	FVector TraceEndLocation;

	//The type of trace to perform
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Ability|Trace")
	TEnumAsByte<ETraceTypeQuery> DesiredTraceType = TraceTypeQuery2;

protected:

	//Performs a simple line trace
	// @param StartLocation - The start location of the trace
	// @param EndLocation - The end location of the trace
	// @param TraceChannel - The channel to trace against
	// @param bDrawDebug - Should the trace be drawn in the world
	// @param OutHitResult - The hit result of the trace
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Jupiter|Ability|Trace", meta =( DisplayName="Try Simple Line Trace"))
	bool TrySimpleLineTrace(FVector StartLocation, FVector EndLocation, ETraceTypeQuery TraceQuery, bool bDrawDebug, FHitResult& OutHitResult);

	/**
	 * @brief Performs the ability trace as defined by the provided TraceType
	 * @return True if the trace hit something
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Jupiter|Ability|Trace", meta =( DisplayName="Perform Ability Trace"))
	bool PerformAbilityTrace();
};

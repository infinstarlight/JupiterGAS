// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/Traces/JupiterGameplayAbility_Trace.h"

#include "Kismet/KismetSystemLibrary.h"

bool UJupiterGameplayAbility_Trace::TrySimpleLineTrace_Implementation(FVector StartLocation, FVector EndLocation,
                                                                      ETraceTypeQuery TraceQuery, bool bDrawDebug, FHitResult& OutHitResult)
{
	if(StartLocation.IsZero() || EndLocation.IsZero())
	{
		//UE_LOG(LogTemp, Error, TEXT("StartLocation or EndLocation is Zero!"));
		return false;
	}
	
	bool bHit = false;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(GetOwningActorFromActorInfo());
	QueryParams.bTraceComplex = bShouldTraceComplex;
	

	bHit = UKismetSystemLibrary::LineTraceSingle(GetWorld(), StartLocation, EndLocation, TraceQuery, bShouldTraceComplex, ActorsToIgnore, EDrawDebugTrace::ForOneFrame, OutHitResult, true, FColor::Red, FColor::Green, 1.0f);
	
	return bHit;
}

bool UJupiterGameplayAbility_Trace::PerformAbilityTrace_Implementation()
{
	bool bTraceHit = false;

	switch(TraceType)
	{
		case EAbilityTraceType::ATT_Line:
		{
			FVector StartLocation = GetActorInfo().AvatarActor->GetActorLocation();
			FVector EndLocation = StartLocation + (GetActorInfo().AvatarActor->GetActorForwardVector() * TraceDistance);
			FHitResult HitResult;
			bTraceHit = TrySimpleLineTrace(StartLocation, EndLocation, DesiredTraceType, true, HitResult);
			break;
		}
	case EAbilityTraceType::ATT_Custom:
			{
				//Custom trace logic here
				break;
			}
		default:
			break;
	}
	
	return bTraceHit;
}

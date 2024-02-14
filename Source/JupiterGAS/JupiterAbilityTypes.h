// Created by: Infinity Starlight Studios

#pragma once


#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "GameplayTagContainer.h"
#include "JupiterAbilityTypes.generated.h"


// The following are common enums and structs that are used in the JupiterGAS plugin
// This specific file is used for Gameplay Ability System (GAS) related types

UENUM(BlueprintType)
enum class EAbilityTraceType : uint8
{
	ATT_None UMETA(DisplayName = "None"),
	ATT_Line UMETA(DisplayName = "Line", ToolTip = "Simple line trace"),
	ATT_Sphere UMETA(DisplayName = "Sphere", ToolTip = "Simple sphere trace"),
	ATT_Box UMETA(DisplayName = "Box", ToolTip = "Simple box trace"),
	ATT_Capsule UMETA(DisplayName = "Capsule", ToolTip = "Simple capsule trace"),
	ATT_Custom UMETA(DisplayName = "Custom", ToolTip = "Perform a custom trace, using your own logic"),
	ATT_MAX UMETA(DisplayName = "MAX", Hidden),
};

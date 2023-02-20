#pragma once

UENUM(BlueprintType)
enum class ESpeedMode : uint8
{
	ESM_Jog UMETA(DisplayName = "Jog"),
	ESM_Sprint UMETA(DisplayName = "Sprint"),
	EMS_MAX UMETA(DisplayName = "MAX")
};
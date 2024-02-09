#pragma once


UENUM(BlueprintType)
enum class EHexDirection : uint8 {
	NORTH_WEST	UMETA(DisplayName = "NORTH_WEST"),
	NORTH_EAST	UMETA(DisplayName = "NORTH_EAST"),
	EAST		UMETA(DisplayName = "EAST"),
	SOUTH_EAST	UMETA(DisplayName = "SOUTH_EAST"),
	SOUTH_WEST	UMETA(DisplayName = "SOUTH_WEST"),
	WEST		UMETA(DisplayName = "WEST"),
	COUNT
};
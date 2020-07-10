// Copyright (C) 2020, Doga Can Yanikoglu

#pragma once

#include "CoreMinimal.h"
#include "ALSMathLibrary.generated.h"

struct FALSComponentAndTransform;
class UCapsuleComponent;

/**
 * Math library functions for ALS
 */
UCLASS()
class ALSV4_CPP_API UALSMathLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static FTransform MantleComponentLocalToWorld(const FALSComponentAndTransform& CompAndTransform);

	static TPair<float, float> FixDiagonalGamepadValues(const float Y, const float X);

	UFUNCTION(BlueprintCallable)
	static FTransform TransfromSub(const FTransform& T1, const FTransform& T2)
	{
		return FTransform(T1.GetRotation().Rotator() - T2.GetRotation().Rotator(),
		                  T1.GetLocation() - T2.GetLocation(), T1.GetScale3D() - T2.GetScale3D());
	}

	UFUNCTION(BlueprintCallable)
	static FTransform TransfromAdd(const FTransform& T1, const FTransform& T2)
	{
		return FTransform(T1.GetRotation().Rotator() + T2.GetRotation().Rotator(),
		                  T1.GetLocation() + T2.GetLocation(), T1.GetScale3D() + T2.GetScale3D());
	}

	UFUNCTION(BlueprintCallable)
	static FVector GetCapsuleBaseLocation(const float ZOffset, UCapsuleComponent* Capsule);

	UFUNCTION(BlueprintCallable)
	static FVector GetCapsuleLocationFromBase(FVector BaseLocation, const float ZOffset, UCapsuleComponent* Capsule);

	UFUNCTION(BlueprintCallable)
	static bool CapsuleHasRoomCheck(UCapsuleComponent* Capsule, FVector TargetLocation, float HeightOffset,
	                                float RadiusOffset);
};
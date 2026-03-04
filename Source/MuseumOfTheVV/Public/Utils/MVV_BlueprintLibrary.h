// Copyright Virtuous Vagrant

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MVV_BlueprintLibrary.generated.h"

UENUM(BlueprintType)
enum class EHitDirection : uint8
{
	Left,
	Right,
	Forward,
	Back
};


UCLASS()
class MUSEUMOFTHEVV_API UMVV_BlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/*
	* A `BlueprintPure` function is shown as a node with no execution pin.
	* By default functions marked `const` will be exposed as pure functions.
	* To make a const function not a pure function, use `BlueprintPure=false`.
	* Pure functions do not cache their results, so be careful when doing any non-trivial amount of work a blueprint pure function.
	* It is good practice to avoid outputting array properties in blueprint pure functions.
	*/
	UFUNCTION(BlueprintPure)
	static EHitDirection GetHitDirection(const FVector& TargetForward, const FVector& ToInstigator);

	UFUNCTION(BlueprintPure)
	static FName GetHitDirectionName(const EHitDirection& HitDirection);
	
};

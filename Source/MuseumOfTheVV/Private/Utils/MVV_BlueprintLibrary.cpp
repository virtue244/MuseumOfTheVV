// Copyright Virtuous Vagrant


#include "Utils/MVV_BlueprintLibrary.h"

EHitDirection UMVV_BlueprintLibrary::GetHitDirection(const FVector& TargetForward, const FVector& ToInstigator)
{
	// ||A|| ||B|| Cos(theta)
	// Cos(theta) = adj/hyp
	const float Dot = FVector::DotProduct(TargetForward, ToInstigator);
	if (Dot < -0.5f)
	{
		return EHitDirection::Back;	
	}
	if (Dot < 0.5f)
	{
		//Either Left or Right
		// ||A|| ||B|| Sin(theta)
		// Sin(theta) = opp/hyp
		// Perpendicular = Right <-> Left
		const FVector Cross = FVector::CrossProduct(TargetForward, ToInstigator);
		if (Cross.Z < 0.f)
		{
			return EHitDirection::Left;
		}
		return EHitDirection::Right;
	}
	return EHitDirection::Forward;
}

FName UMVV_BlueprintLibrary::GetHitDirectionName(const EHitDirection& HitDirection)
{
	switch (HitDirection)
	{
	case EHitDirection::Left: return FName("Left");
	case EHitDirection::Right: return FName("Right");
	case EHitDirection::Forward: return FName("Forward");
	case EHitDirection::Back: return FName("Back");
	default: return FName("None");
	}
}

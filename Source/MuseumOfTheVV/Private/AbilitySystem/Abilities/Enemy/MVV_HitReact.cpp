// Copyright Virtuous Vagrant


#include "AbilitySystem/Abilities/Enemy/MVV_HitReact.h"

void UMVV_HitReact::CacheHitDirectionVectors(AActor* Instigator)
{
	AvatarForward = GetAvatarActorFromActorInfo()->GetActorForwardVector();

	const FVector AvatarLocation = GetAvatarActorFromActorInfo()->GetActorLocation();
	const FVector InstigatorLocation = Instigator->GetActorLocation();

	// ToInstigator is a normalized FVector representing the direction from avatar to instigator
	// F = Float precision, Vector = 3D direction with magnitude (normalized to length 1)
	ToInstigator = InstigatorLocation - AvatarLocation;
	
	// Because ToInstigator is a direct object (not a pointer), we use the dot operator (.) to call the FVector member function Normalize().
	ToInstigator.Normalize();
}
// Copyright Virtuous Vagrant


#include "AbilitySystem/Abilities/Enemy/MVV_HitReact.h"

void UMVV_HitReact::CacheHitDirectionVectors(AActor* Instigator)
{
	AvatarForward = GetAvatarActorFromActorInfo()->GetActorForwardVector();

	const FVector AvatarLocation = GetAvatarActorFromActorInfo()->GetActorLocation();
	const FVector InstigatorLocation = Instigator->GetActorLocation();

	ToInsigator = InstigatorLocation - AvatarLocation;
	ToInsigator.Normalize();
}

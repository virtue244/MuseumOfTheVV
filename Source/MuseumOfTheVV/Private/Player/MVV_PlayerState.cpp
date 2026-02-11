// Copyright Virtuous Vagrant


#include "Player/MVV_PlayerState.h"

#include "AbilitySystemComponent.h"

AMVV_PlayerState::AMVV_PlayerState()
{
	// Set the frequency at which this object will be considered for replication.
	// TODO Let's explore replication
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* AMVV_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

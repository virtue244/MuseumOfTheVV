// Copyright Virtuous Vagrant


#include "Player/MVV_PlayerState.h"

#include "AbilitySystemComponent.h"

AMVV_PlayerState::AMVV_PlayerState()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* AMVV_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

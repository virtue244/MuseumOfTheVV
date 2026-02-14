// Copyright Virtuous Vagrant


#include "Player/MVV_PlayerState.h"

#include "AbilitySystemComponent.h"

AMVV_PlayerState::AMVV_PlayerState()
{
	// Set the frequency at which this object will be considered for replication.
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	/* The AbilitySystemComponent (ASC) uses "Replication Modes" to control how much data about Gameplay Effects is sent to other players.
	*	Full: Every GameplayEffect is replicated to every client. This is the heaviest mode and is typically only used for Single Player games or specific debug scenarios.
	*	Mixed: The Owning Client (you) gets full info (durations, stacks), while Simulated Proxies (other players looking at you) only get minimal info like Tags and Cues. This is the standard for multiplayer player-controlled characters.
	*	Minimal: No GameplayEffect details are replicated to anyone; only Tags and Cues are sent. This is highly efficient and recommended for AI/NPCs where other players don't need to see specific buff durations.
	 */
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* AMVV_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

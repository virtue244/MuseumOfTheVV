// Copyright Virtuous Vagrant


#include "Characters/MVV_EnemyCharacter.h"

#include "AbilitySystem/MVV_AbilitySystemComponent.h"
#include "AbilitySystem/MVV_AttributeSet.h"


// Sets default values
AMVV_EnemyCharacter::AMVV_EnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UMVV_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	/*
	* When a character is controlled by the server (AI), it doesn't have an "owning client" (a human player sitting at a screen controlling it). Connected players don't need to know the underlying math or exact durations of the buffs/debuffs applied to an enemy; they just need to see the results.
	*	- What replicates to clients: Gameplay Tags (e.g., `State.Stunned`) and Gameplay Cues (e.g., particle effects, hit sounds).
	*	- What DOESN'T replicate: The Gameplay Effects themselves (the actual objects managing modifiers, exact duration timers, etc.).
	*	- Why: It saves a massive amount of network traffic. The server calculates the math locally, replicates the resulting Attributes (like Health), and sends the Tags/Cues to the clients so they can play animations or update health bars.
	*/
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UMVV_AttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AMVV_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AMVV_EnemyCharacter::GetAttributeSet() const
{
	return AttributeSet;
}


void AMVV_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(AbilitySystemComponent)) return;
	
	GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);
	OnASCInitialized.Broadcast(GetAbilitySystemComponent(), GetAttributeSet());

	// I believe this means that we will only call GiveStartupAbilities() if this is executing on the server.
	// Everything executed before the has authority check will be on both the server and client but everything after is only on the server.
	if (!HasAuthority()) return;

	GiveStartupAbilities();
	InitializeAttributes();
	
}




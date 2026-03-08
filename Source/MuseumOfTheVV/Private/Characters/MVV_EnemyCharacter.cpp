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
	// TODO - Why are we using minimal here?
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




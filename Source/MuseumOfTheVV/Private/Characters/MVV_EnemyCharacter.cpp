// Copyright Virtuous Vagrant


#include "Characters/MVV_EnemyCharacter.h"

#include "AbilitySystem/MVV_AbilitySystemComponent.h"


// Sets default values
AMVV_EnemyCharacter::AMVV_EnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UMVV_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
}

UAbilitySystemComponent* AMVV_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AMVV_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(AbilitySystemComponent)) return;
	
	GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);
	
	if (!HasAuthority()) return;

	GiveStartupAbilities();
	
}




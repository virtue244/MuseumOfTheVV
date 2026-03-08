// Copyright Virtuous Vagrant


#include "MuseumOfTheVV/Public/Characters/MVV_BaseCharacter.h"

#include "AbilitySystemComponent.h"


// Sets default values
AMVV_BaseCharacter::AMVV_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	// Tick and refresh bone transforms whether rendered or not - for bone updates on a dedicated server
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

UAbilitySystemComponent* AMVV_BaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

void AMVV_BaseCharacter::GiveStartupAbilities()
{
	if (!IsValid(GetAbilitySystemComponent())) return;
	
	for (const auto& Ability : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability);
		GetAbilitySystemComponent()->GiveAbility(AbilitySpec);
	}
}

void AMVV_BaseCharacter::InitializeAttributes()
{
	checkf(IsValid(InitializeAttributesEffect), TEXT("InitializeAttributeEffect not set."));
	
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(InitializeAttributesEffect, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}




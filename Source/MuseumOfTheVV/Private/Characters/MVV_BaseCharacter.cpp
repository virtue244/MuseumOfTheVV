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




// Copyright Virtuous Vagrant

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "MVV_AbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MUSEUMOFTHEVV_API UMVV_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	virtual void OnGiveAbility(FGameplayAbilitySpec& AbilitySpec) override;
	virtual void OnRep_ActivateAbilities() override;

private:

	void HandleAutoActivateAbilities(const FGameplayAbilitySpec& AbilitySpec);
	
	


};

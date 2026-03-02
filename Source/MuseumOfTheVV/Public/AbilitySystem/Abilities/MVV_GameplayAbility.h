// Copyright Virtuous Vagrant

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MVV_GameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class MUSEUMOFTHEVV_API UMVV_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MVV|Debug")
	bool bDrawDebugs = false;
	
};

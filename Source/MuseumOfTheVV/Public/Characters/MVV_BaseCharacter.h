// Copyright Virtuous Vagrant
// All current plan is for this class to be inhereted from the Player and Enemy Characters

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "MVV_BaseCharacter.generated.h"


class UAttributeSet;
class UGameplayEffect;
class UGameplayAbility;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FASCInitialized, UAbilitySystemComponent*, ASC, UAttributeSet*, AS);

UCLASS(Abstract)
class MUSEUMOFTHEVV_API AMVV_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AMVV_BaseCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UAttributeSet* GetAttributeSet() const { return nullptr; }

	UPROPERTY(BlueprintAssignable)
	FASCInitialized OnASCInitialized;

protected:
	void GiveStartupAbilities();
	void InitializeAttributes() const;
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "MVV|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "MVV|Effects")
	TSubclassOf<UGameplayEffect> InitializeAttributesEffect;
};

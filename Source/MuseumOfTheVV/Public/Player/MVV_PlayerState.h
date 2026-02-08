// Copyright Virtuous Vagrant

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "MVV_PlayerState.generated.h"

class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class MUSEUMOFTHEVV_API AMVV_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AMVV_PlayerState();
	// TODO Do we need to inheret IAbililitySystemInterface in this class? Seems like I am using it in the Base Character class.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:
	
	UPROPERTY(VisibleAnywhere, Category="MVV|Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};

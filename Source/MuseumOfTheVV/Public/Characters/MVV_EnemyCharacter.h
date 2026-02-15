// Copyright Virtuous Vagrant

#pragma once

#include "CoreMinimal.h"
#include "MVV_BaseCharacter.h"
#include "MVV_EnemyCharacter.generated.h"

class UAbilitySystemComponent;

UCLASS()
class MUSEUMOFTHEVV_API AMVV_EnemyCharacter : public AMVV_BaseCharacter
{
	GENERATED_BODY()

public:
	
	AMVV_EnemyCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

};

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MVV|Debug")
	bool bDrawDebugs = false;
	
};

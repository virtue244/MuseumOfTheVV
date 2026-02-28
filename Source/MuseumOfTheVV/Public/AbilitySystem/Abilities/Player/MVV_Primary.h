// Copyright Virtuous Vagrant

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/MVV_GameplayAbility.h"
#include "MVV_Primary.generated.h"

/**
 * 
 */
UCLASS()
class MUSEUMOFTHEVV_API UMVV_Primary : public UMVV_GameplayAbility
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="MVV|Abilities")
	void HitBoxOverlapTest();

private:
	UPROPERTY(EditDefaultsOnly, Category = "MVV|Abilities")
	float HitBoxRadius = 100.f;

	UPROPERTY(EditDefaultsOnly, Category = "MVV|Abilities")
	float HitBoxForwardOffset = 200.f;

	UPROPERTY(EditDefaultsOnly, Category = "MVV|Abilities")
	float HitBoxElevationOffset = 20.f;
};

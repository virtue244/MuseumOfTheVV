// Copyright Virtuous Vagrant

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/MVV_GameplayAbility.h"
#include "MVV_HitReact.generated.h"

/**
 * 
 */
UCLASS()
class MUSEUMOFTHEVV_API UMVV_HitReact : public UMVV_GameplayAbility
{
	// GENERATED_BODY() is an Unreal Engine macro that generates essential boilerplate code for UObject-derived classes,
	// enabling reflection, serialization, and integration with Unreal's object system.
	GENERATED_BODY()
	
public:

	// UFUNCTION is an Unreal Engine macro that exposes this C++ function to the reflection system,
	// enabling Blueprint access, editor integration, and network replication capabilities.
	/*
	* What UFUNCTION Actually Enables:
		1. Blueprint Integration: Blueprints can call the function
		2. Network Replication: Can be marked for server/client RPC calls
		3. Editor Integration: Can appear in editor menus/toolbars
		4. Reflection System: Engine knows the function exists at runtime
		5. Serialization Support: Function calls can be saved/loaded
	 */
	UFUNCTION(BlueprintCallable, Category="MVV|Abilities")
	void CacheHitDirectionVectors(AActor* Instigator);

	// UPROPERTY is an Unreal Engine macro that exposes this C++ variable to the reflection system,
	// enabling Blueprint access, editor Details panel visibility, serialization, and network replication.
	UPROPERTY(BlueprintReadOnly, Category="MVV|Abilities")
	FVector AvatarForward;
	
	UPROPERTY(BlueprintReadOnly, Category="MVV|Abilities")
	FVector ToInstigator;
};
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
	// This is the class that holds the gameplay ability system component and the player character will reference the player state to retrieve this variable
	// This will likely be different for an Enemy Character as we will probably have the AbilitySystem Component on the character itself, I think.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:

	/* Gameplay Ability System
	 * -----------------------
	* The Ability System Component (The Brain)
	*	Keeps track of everything the character can do.
	*	Remembers if the character is currently "stunned", "poisoned", pr "super strong".
	*	In Multiplayer games, it makes sure everyone's screen sees the same thing at the same time.
	*
	* Gameplay Abilities (The Actions)
	*	- Play Animation
	*	- Line Trace
	*	- Get Hit Actor
	*	
	* Gameplay Effects (Rules of Change)
	*	- Calculate Damage Done by Ability
	*	
	* Gameplay Attributes (Stats)
	*	- Alter Health Attribute
	*	
	* Gameplay Cues (Special Effects / FX)
	*	- Making an actor turn red on hit
	*
	* Gameplay Tags (The Labels)
	*	- If you have the tag State.Frozen you cant perform the Ability.Run to move
	*
	* Gameplay Tasks
	*	What are tasks?
	*	- They are essentially the workers that handle the actual execution of complex gameplay mechanics in an asynchronous manner within the ability system.
	*	- Gameplay Tasks help coordinate and execute these various components when abilities are used in the game.


	*/
	UPROPERTY(VisibleAnywhere, Category="MVV|Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};

// Copyright Virtuous Vagrant
// This will be designed to be a Playable Character

#pragma once

#include "CoreMinimal.h"
#include "MVV_BaseCharacter.h"
#include "MVV_PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class MUSEUMOFTHEVV_API AMVV_PlayerCharacter : public AMVV_BaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMVV_PlayerCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void PossessedBy(AController* NewController) override;

private:

	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<UCameraComponent> FollowCamera;

};

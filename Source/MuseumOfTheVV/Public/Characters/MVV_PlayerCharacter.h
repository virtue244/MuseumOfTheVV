// Copyright Vertiu

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

private:

	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<UCameraComponent> FollowCamera;

};

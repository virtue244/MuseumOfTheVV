// Copyright Virtuous Vagrant
// All current plan is for this class to be inhereted from the Player and Enemy Characters

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MVV_BaseCharacter.generated.h"

UCLASS(Abstract)
class MUSEUMOFTHEVV_API AMVV_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMVV_BaseCharacter();

};

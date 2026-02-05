// Copyright Virtuous Vagrant


#include "MuseumOfTheVV/Public/Characters/MVV_BaseCharacter.h"


// Sets default values
AMVV_BaseCharacter::AMVV_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	// Tick and refresh bone transforms whether rendered or not - for bone updates on a dedicated server
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}




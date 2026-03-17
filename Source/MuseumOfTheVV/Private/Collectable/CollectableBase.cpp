// Copyright Virtuous Vagrant


#include "Collectable/CollectableBase.h"


ACollectableBase::ACollectableBase()
{
	
	PrimaryActorTick.bCanEverTick = true;
}

void ACollectableBase::BeginPlay()
{
	Super::BeginPlay();
	
}



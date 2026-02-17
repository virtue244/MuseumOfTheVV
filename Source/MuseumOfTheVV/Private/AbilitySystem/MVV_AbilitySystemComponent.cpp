// Copyright Virtuous Vagrant


#include "AbilitySystem/MVV_AbilitySystemComponent.h"


// Sets default values for this component's properties
UMVV_AbilitySystemComponent::UMVV_AbilitySystemComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UMVV_AbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


// Called every frame
void UMVV_AbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}


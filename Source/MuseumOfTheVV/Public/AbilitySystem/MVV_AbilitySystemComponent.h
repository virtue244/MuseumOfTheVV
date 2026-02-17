// Copyright Virtuous Vagrant

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "MVV_AbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MUSEUMOFTHEVV_API UMVV_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	
	UMVV_AbilitySystemComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
						   FActorComponentTickFunction* ThisTickFunction) override;
	

protected:
	
	virtual void BeginPlay() override;


};

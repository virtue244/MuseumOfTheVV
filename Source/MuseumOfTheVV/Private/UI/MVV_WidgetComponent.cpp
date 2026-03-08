// Copyright Virtuous Vagrant


#include "UI/MVV_WidgetComponent.h"

#include "AbilitySystem/MVV_AbilitySystemComponent.h"
#include "AbilitySystem/MVV_AttributeSet.h"
#include "Characters/MVV_BaseCharacter.h"


void UMVV_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	InitAbilitySystemData();
	if (!IsASCInitialized())
	{
		Character->OnASCInitialized.AddDynamic(this, &ThisClass::OnASCInitialized);
	}
}

void UMVV_WidgetComponent::InitAbilitySystemData()
{
	Character = Cast<AMVV_BaseCharacter>(GetOwner());
	AttributeSet = Cast<UMVV_AttributeSet>(Character->GetAttributeSet());
	AbilitySystemComponent = Cast<UMVV_AbilitySystemComponent>(Character->GetAbilitySystemComponent());
}

bool UMVV_WidgetComponent::IsASCInitialized() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}

void UMVV_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UMVV_AbilitySystemComponent>(ASC);
	AttributeSet = Cast<UMVV_AttributeSet>(AS);

	//TODO: Check if the Attribute Set has been initialized with the first GE
	// If not, bind to some delegate that will be broadcast when it is initialized.
}


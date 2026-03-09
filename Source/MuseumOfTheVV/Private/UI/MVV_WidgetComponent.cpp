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
		return;
	}
	InitializeAttributeDelegate();
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

void UMVV_WidgetComponent::InitializeAttributeDelegate()
{
	if (!AttributeSet->bAttributesInitialized)
	{
		AttributeSet->OnAttributesInitialized.AddDynamic(this, &ThisClass::BindToAttributeChanges);
	}
	else
	{
		BindToAttributeChanges();
	}
}

void UMVV_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UMVV_AbilitySystemComponent>(ASC);
	AttributeSet = Cast<UMVV_AttributeSet>(AS);

	if (!IsASCInitialized()) return;
	InitializeAttributeDelegate();
}

void UMVV_WidgetComponent::BindToAttributeChanges()
{
	//TODO: Listen for changes to gameplay attributes and update our widgets accordingly
	
}


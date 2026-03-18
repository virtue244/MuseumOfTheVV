// Copyright Virtuous Vagrant


#include "UI/MVV_WidgetComponent.h"

#include "AbilitySystem/MVV_AbilitySystemComponent.h"
#include "AbilitySystem/MVV_AttributeSet.h"
#include "Blueprint/WidgetTree.h"
#include "Characters/MVV_BaseCharacter.h"
#include "UI/MVV_AttributeWidget.h"


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

// TODO - Need to identify how Add Dynamic connects to the Dynamic Delegate
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
	for (const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair : AttributeMap)
	{
		BindWidgetToAttributeChanges((GetUserWidgetObject()), Pair); //For checking the owned widget object

		GetUserWidgetObject()->WidgetTree->ForEachWidget([this, &Pair](UWidget* ChildWidget)
		{
			BindWidgetToAttributeChanges(ChildWidget, Pair);
		});
	}
	
}

void UMVV_WidgetComponent::BindWidgetToAttributeChanges(UWidget* WidgetObject,
	const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const
{
	UMVV_AttributeWidget*  AttributeWidget = Cast<UMVV_AttributeWidget>(WidgetObject);
	if (!IsValid(AttributeWidget)) return; // We only care about MVV_AttributeWidgets
	if (!AttributeWidget->MatchesAttributes(Pair)) return; //Only Subscribe to matching Attributes

	AttributeWidget->OnAttributeChange(Pair, AttributeSet.Get()); // For Initial Values

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Key).AddLambda([this, AttributeWidget, &Pair](const FOnAttributeChangeData& AttributeChangeData)
	{
		AttributeWidget->OnAttributeChange(Pair, AttributeSet.Get()); // For change during the game.
	});
	
}


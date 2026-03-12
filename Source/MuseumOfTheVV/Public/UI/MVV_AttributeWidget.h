// Copyright Virtuous Vagrant

#pragma once

#include "AbilitySystem/MVV_AttributeSet.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MVV_AttributeWidget.generated.h"



/**
 * 
 */
UCLASS()
class MUSEUMOFTHEVV_API UMVV_AttributeWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MVV|Attributes")
	FGameplayAttribute Attribute;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MVV|Attributes")
	FGameplayAttribute MaxAttribute;

	void OnAttributeChange(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair, UMVV_AttributeSet* AttributeSet);
	bool MatchesAttributes(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Attribute Change"))
	void BP_OnAttributeChange(float NewValue, float NewMaxValue);
};

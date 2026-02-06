// Copyright Virtuous Vagrant

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MVV_PlayerController.generated.h"


class UInputAction;
class UInputMappingContext;
struct FInputActionValue;


UCLASS()
class MUSEUMOFTHEVV_API AMVV_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;

private:
	// How I can assign my IMC and IAs to this object once the PlayerController is instantiated as a Blueprint
	UPROPERTY(EditDefaultsOnly, Category = "MVV|Input")
	TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts;

	UPROPERTY(EditDefaultsOnly, Category = "MVV|Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "MVV|Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "MVV|Input")
	TObjectPtr<UInputAction> LookAction;

	// Functions within this PlayerController that are called when a particular action is needed (Started, Completed or Triggered)
	void Jump();
	void StopJumping();
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};

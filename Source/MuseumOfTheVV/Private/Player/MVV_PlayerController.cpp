// Copyright Virtuous Vagrant


#include "Player/MVV_PlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "HeadMountedDisplayTypes.h"
#include "InputMappingContext.h"
#include "GameFramework/Character.h"

void AMVV_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	// This retrieves the "Manager" responsible for a specific player's input
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (!IsValid(InputSubsystem)) return;

	for (UInputMappingContext* Context:InputMappingContexts)
	{
		// Will activate^ a mapping context and since InputMappingContexts is an array, we look through and activate them all
		// ^Activate mean that you inform the engine to start listening for the specific keys defined in that Input Mapping Context
		InputSubsystem->AddMappingContext(Context, 0);
	}
	
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (!IsValid(EnhancedInputComponent)) return;

	// Now Bind each Input Action with it's Trigger and Function
	/*
	* Started: Fires once the moment you press the key (ideal for jumping).
	* Triggered: Fires every frame/update while the input is active (ideal for continuous movement or looking).
	* Completed: Fires once when you release the key
	 */
	EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Started, this, &ThisClass::Jump);
	EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Completed, this, &ThisClass::StopJumping);
	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered, this, &ThisClass::Move);
	EnhancedInputComponent->BindAction(LookAction,ETriggerEvent::Triggered, this, &ThisClass::Look);
}

void AMVV_PlayerController::Jump()
{
	if (!IsValid(GetCharacter())) return;
	GetCharacter()->Jump();
}

void AMVV_PlayerController::StopJumping()
{
	if (!IsValid(GetCharacter())) return;
	GetCharacter()->StopJumping();
}

void AMVV_PlayerController::Move(const FInputActionValue& Value)
{

	// TODO - I need to spend more time here to understand the axis flip-flopping 
	if (!IsValid(GetPawn())) return;
	const FVector2D MovementVector = Value.Get<FVector2D>();

	// Find which way is forward
	const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// Apply Vectors
	GetPawn()->AddMovementInput(ForwardDirection, MovementVector.Y);
	GetPawn()->AddMovementInput(RightDirection, MovementVector.X);
	
}

void AMVV_PlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
	
	
}

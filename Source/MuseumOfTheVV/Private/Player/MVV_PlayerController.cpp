// Copyright Virtuous Vagrant


#include "Player/MVV_PlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "GameplayTags/MVVTags.h"

#include "DrawDebugHelpers.h"

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
	EnhancedInputComponent->BindAction(PrimaryAction,ETriggerEvent::Started, this, &ThisClass::ExecutePrimaryAction);
	EnhancedInputComponent->BindAction(SecondaryAction,ETriggerEvent::Started, this, &ThisClass::ExecuteSecondaryAction);
	EnhancedInputComponent->BindAction(TertiaryAction,ETriggerEvent::Started, this, &ThisClass::ExecuteTertiaryAction);
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
	if (!IsValid(GetPawn())) return;

	// Extract the data from the input system (INPUT SPACE)
	// X represents Left(A)/Right(D)
	// Y represents Forward(W)/Backwards(S)
	const FVector2D MovementVector = Value.Get<FVector2D>();

	/*
	* YawRotation gets the rotation of the controller (where the player is looking) but zeros out the Pitch and Roll.
	* This prevents the character from trying to walk into the ground or fly into the air if the player looks up or down.
	 */
	const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);

	/* These lines turn that rotation into actual direction arrows (vectors).
	* In Unreal Engine (WORLD SPACE)
	*	X is Forward
	*	-X if Backwards
	*	Y is Right
	*	-Y is Left
	*
	*	1. The World Space (The "Where")
	*	In Unreal Engine’s 3D world coordinate system:
	*		X-Axis is the "Forward" axis (Red arrow in the editor).
	*		Y-Axis is the "Right" axis (Green arrow in the editor).
	*	When the code calls GetUnitAxis(EAxis::X), it is asking: "In the direction the player is looking, which way is 'World Forward'?"
	*
	*	2. The Input Space (The "Value")
	*	When you use a joystick or WASD, the input is usually represented as a 2D coordinate (x,y):
	*		Input X: Horizontal axis (Left/Right).
	*		Input Y: Vertical axis (Forward/Backward).
	 */
	const FVector WorldForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector WorldRightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// Apply Vectors
	// Move the pawn along the World's Forward line using the Input's Vertical value.
	GetPawn()->AddMovementInput(WorldForwardDirection, MovementVector.Y);
	// Move the pawn along the World's Right line using the Input's Horizontal value.
	GetPawn()->AddMovementInput(WorldRightDirection, MovementVector.X);

	/* Debugging Start *\/
	// Get the current location of the character to start the line
	FVector StartLocation = GetPawn()->GetActorLocation();
	
	// --- Draw Forward Vector (Red) ---
	if (MovementVector.Y != 0.f)
	{
		FVector VectorMultiplier = (WorldForwardDirection * 500.f);
		DrawDebugLine(GetWorld(), StartLocation - VectorMultiplier, StartLocation + VectorMultiplier, FColor::Red, false, -1, 0, 5);
	}
	// --- Draw Right Vector (Green) ---
	if (MovementVector.X != 0.f)
	{
		FVector VectorMultiplier = (WorldRightDirection * 500.f);
		DrawDebugLine(GetWorld(), StartLocation - VectorMultiplier, StartLocation + VectorMultiplier, FColor::Green, false, -1, 0, 5);
	}
	/\* Debugging End */
}

void AMVV_PlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	// Yaw is rotation around the Z axis in engine (Left/Right), X relative to the INPUT SYSTEM (Left/Right)
	AddYawInput(LookAxisVector.X);
	// Pitch is rotation around the Y axis in engine (Up/Down), Y relative to the INPUT SYSTEM (Up/Down)
	//																							x~x
	// I am confused by this, thought the axis wouldn't match up, but seems to for some reason (O_o)
	//																						   >-\--<
	//																							 ^
	//																							/ |
	AddPitchInput(LookAxisVector.Y);
	
	
}

void AMVV_PlayerController::ExecutePrimaryAction()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Primary Action"));
	ActivateAbility(MVVTags::MVVAbilities::Primary);
}

void AMVV_PlayerController::ExecuteSecondaryAction()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Secondary Action"));
	ActivateAbility(MVVTags::MVVAbilities::Secondary);
}

void AMVV_PlayerController::ExecuteTertiaryAction()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Tertiary Action"));
	ActivateAbility(MVVTags::MVVAbilities::Tertiary);
}

void AMVV_PlayerController::ActivateAbility(const FGameplayTag& AbilityTag) const
{
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn());
	if (!IsValid(ASC)) return;

	ASC->TryActivateAbilitiesByTag(AbilityTag.GetSingleTagContainer());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, AbilityTag.ToString()+" -> Activated via C++");
}

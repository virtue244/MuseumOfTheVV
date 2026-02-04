// Copyright Vertiu


#include "MuseumOfTheVV/Public/Characters/MVV_PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


AMVV_PlayerCharacter::AMVV_PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	/*
	 * Characters primary collision body
	 */
	GetCapsuleComponent()->InitCapsuleSize(42.f,96.f);

	// Set ACharacter class properties that are inherited from the APawn actor class
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// ACharacter class method to update another object within the ACharacter class, called UCharacterMovementComponent's properties
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.f;

	// Instantiate SpringArm Object
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	// Attach to Root Component
	CameraBoom->SetupAttachment(GetRootComponent());
	// Set Properties of the Object
	CameraBoom->TargetArmLength = 600.0f;
	CameraBoom->bUsePawnControlRotation = true;

	// Instantiate Camera Object
	FollowCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	// Attach to SpringArm
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	// Set Properties of the Object
	FollowCamera->bUsePawnControlRotation = false;
}



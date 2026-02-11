// Copyright Virtuous Vagrant


#include "MuseumOfTheVV/Public/Characters/MVV_PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/MVV_PlayerState.h"


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

UAbilitySystemComponent* AMVV_PlayerCharacter::GetAbilitySystemComponent() const
{
	AMVV_PlayerState* MVVPlayerState = Cast<AMVV_PlayerState>(GetPlayerState());
	if (!IsValid(MVVPlayerState))
	{
		return nullptr;
	}
	return MVVPlayerState->GetAbilitySystemComponent();
	
}

void AMVV_PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!IsValid(GetAbilitySystemComponent())) return;
	// TODO Why do we need this in both the OnRep_PlayerState method and the ProcessedBy method?
	// What does the InitAbilityActorInfo method do?
	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(), this);
}

void AMVV_PlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if (!IsValid(GetAbilitySystemComponent())) return;
	
	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(), this);
}



// Copyright SkyHigh Gaming.


#include "Character/AstraCharacter.h"

#include "AbilitySystemComponent.h"
#include "Player/AstraPlayerState.h"
#include "GameFramework/CharacterMovementComponent.h"

AAstraCharacter::AAstraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

}

void AAstraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the server
	InitAblilityActorInfo();


}

void AAstraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the server
	InitAblilityActorInfo();

}

void AAstraCharacter::InitAblilityActorInfo()
{
	AAstraPlayerState* AstraPlayerState = GetPlayerState<AAstraPlayerState>();
	check(AstraPlayerState);

	AstraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AstraPlayerState, this);
	AbilitySystemComponent = AstraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AstraPlayerState->GetAttributeSet();
}

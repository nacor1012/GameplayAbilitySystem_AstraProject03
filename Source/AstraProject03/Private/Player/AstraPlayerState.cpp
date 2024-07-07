// Copyright SkyHigh Gaming.


#include "Player/AstraPlayerState.h"

#include "AbilitySystem/AstraAttributeSet.h"
#include "AbilitySystem/AstraAbilitySystemComponent.h"

AAstraPlayerState::AAstraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAstraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UAstraAttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AAstraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

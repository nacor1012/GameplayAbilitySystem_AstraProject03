// Copyright SkyHigh Gaming.


#include "Player/AstraPlayerState.h"

#include "Net/UnrealNetwork.h"
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

void AAstraPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AAstraPlayerState, Level)
}

UAbilitySystemComponent* AAstraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAstraPlayerState::OnRep_Level(int32 OldLevel)
{

}

// Copyright SkyHigh Gaming.


#include "AbilitySystem/Abilitys/AstraProjectileSpell.h"

#include "Kismet/KismetSystemLibrary.h"

void UAstraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	UKismetSystemLibrary::PrintString(this, FString("ActivateAbility (C++")), true, true, FLinearColor::Yellow, 3);
}

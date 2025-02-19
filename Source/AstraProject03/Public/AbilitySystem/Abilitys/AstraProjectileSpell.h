// Copyright SkyHigh Gaming.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilitys/AstraGameplayAbility.h"
#include "AstraProjectileSpell.generated.h"

class AAstraProjectile;

UCLASS()
class ASTRAPROJECT03_API UAstraProjectileSpell : public UAstraGameplayAbility
{
	GENERATED_BODY()
	
protected:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AAstraProjectile> ProjectileClass;
};

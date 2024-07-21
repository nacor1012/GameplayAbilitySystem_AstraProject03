// Copyright SkyHigh Gaming.


#include "AbilitySystem/AstraAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

UAstraAttributeSet::UAstraAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(20.f);
	InitMaxMana(90.f);
}

void UAstraAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAstraAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAstraAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAstraAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAstraAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UAstraAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}

	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
}

void UAstraAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props)
{
	// Source = Causer of the effect, Target = target of the effect (owner of this AS)

	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	const UAbilitySystemComponent* SourceASC = EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(SourceASC) && SourceASC->AbilityActorInfo.IsValid() && SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		AActor* SourceAvatarActor = SourceASC->AbilityActorInfo->AvatarActor.Get();
		const AController* SourceController = SourceASC->AbilityActorInfo->PlayerController.Get();
		if (SourceController == nullptr && SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(SourceAvatarActor))
			{
				SourceController = Pawn->GetController();
			}
		}
		if (SourceController)
		{
			ACharacter* SourseCharacter = Cast <ACharacter>(SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		AActor* TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		AController* TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		ACharacter* TargetCharacter = Cast<ACharacter>(TargetAvatarActor);
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetAvatarActor);
	}
}

void UAstraAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	

}

void UAstraAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAstraAttributeSet, Health, OldHealth);
}

void UAstraAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAstraAttributeSet, MaxHealth, OldMaxHealth);
}

void UAstraAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAstraAttributeSet, Mana, OldMana);
}

void UAstraAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAstraAttributeSet, MaxMana, OldMaxMana);
}



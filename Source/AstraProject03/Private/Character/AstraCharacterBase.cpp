// Copyright SkyHigh Gaming.


#include "Character/AstraCharacterBase.h"

#include "AbilitySystemComponent.h"


AAstraCharacterBase::AAstraCharacterBase()
{
 
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAstraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AAstraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAstraCharacterBase::InitAblilityActorInfo()
{

}

void AAstraCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AAstraCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes,  1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
}



// Copyright SkyHigh Gaming.


#include "Character/AstraCharacterBase.h"

#include "AbilitySystemComponent.h"


AAstraCharacterBase::AAstraCharacterBase()
{
 
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	StaticWeapon = CreateDefaultSubobject<UStaticMeshComponent>("StaticWeapon");
	StaticWeapon->SetupAttachment(GetMesh(), FName("StaticWeaponHandSocket"));
	StaticWeapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
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
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AAstraCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes,  1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultVitalAttributes, 1.f);
}



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

void AAstraCharacterBase::InitializePrimaryAttributes() const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(DefaultPrimaryAttributes);
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultPrimaryAttributes, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}



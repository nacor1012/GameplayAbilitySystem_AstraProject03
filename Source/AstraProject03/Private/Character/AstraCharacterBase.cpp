// Copyright SkyHigh Gaming.


#include "Character/AstraCharacterBase.h"


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



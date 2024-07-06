// Copyright SkyHigh Gaming.


#include "Character/AstraCharacterBase.h"


AAstraCharacterBase::AAstraCharacterBase()
{
 
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Shield = CreateDefaultSubobject<USkeletalMeshComponent>("Shield");
	Shield->SetupAttachment(GetMesh(), FName("ShieldHandSocket"));
	Shield->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}


void AAstraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}



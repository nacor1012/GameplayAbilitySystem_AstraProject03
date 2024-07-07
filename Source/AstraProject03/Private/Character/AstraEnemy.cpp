// Copyright SkyHigh Gaming.


#include "Character/AstraEnemy.h"

#include "AbilitySystem/AstraAttributeSet.h"
#include "AbilitySystem/AstraAbilitySystemComponent.h"
#include "AstraProject03/AstraProject03.h"

AAstraEnemy::AAstraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAstraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAstraAttributeSet>("AttributeSet");

}

void AAstraEnemy::HighLightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Shield->SetRenderCustomDepth(true);
	Shield->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAstraEnemy::UnHighLightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
	Shield->SetRenderCustomDepth(false);
	
}

void AAstraEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	AbilitySystemComponent->InitAbilityActorInfo(this, this);

}

// Copyright SkyHigh Gaming.


#include "Character/AstraEnemy.h"
#include "AstraProject03/AstraProject03.h"

AAstraEnemy::AAstraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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

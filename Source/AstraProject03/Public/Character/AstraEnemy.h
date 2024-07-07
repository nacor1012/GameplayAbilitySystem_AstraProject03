// Copyright SkyHigh Gaming.

#pragma once

#include "CoreMinimal.h"
#include "Character/AstraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AstraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class ASTRAPROJECT03_API AAstraEnemy : public AAstraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	
public:

	AAstraEnemy();

	virtual void HighLightActor() override;
	virtual void UnHighLightActor() override;

};

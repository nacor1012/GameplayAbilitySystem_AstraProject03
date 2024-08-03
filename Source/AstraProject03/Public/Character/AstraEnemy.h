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

	/** Enemy Interface */
	virtual void HighLightActor() override;
	virtual void UnHighLightActor() override;
	/** End Enemy Interface */

	/** Combat Interface */
    virtual int32 GetPlayerLevel() override;
    /** end Combat Interface */

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Shield;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Bow;

	virtual void InitAblilityActorInfo();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

};

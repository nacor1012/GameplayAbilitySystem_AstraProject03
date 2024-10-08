// Copyright SkyHigh Gaming.

#pragma once

#include "CoreMinimal.h"
#include "Character/AstraCharacterBase.h"
#include "AstraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ASTRAPROJECT03_API AAstraCharacter : public AAstraCharacterBase
{
	GENERATED_BODY()
	
public:

	AAstraCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	/** Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/** end Combat Interface */

private:

	virtual void InitAblilityActorInfo() override;

};

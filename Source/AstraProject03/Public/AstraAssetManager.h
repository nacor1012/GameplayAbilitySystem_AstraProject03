// Copyright SkyHigh Gaming.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AstraAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class ASTRAPROJECT03_API UAstraAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:

	static UAstraAssetManager& Get();

protected:

	virtual void StartInitialLoading() override;
};

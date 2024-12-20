// Copyright SkyHigh Gaming.


#include "AstraAssetManager.h"
#include "AstraGameplayTags.h"

UAstraAssetManager& UAstraAssetManager::Get()
{
	check(GEngine);

	UAstraAssetManager* AstraAssetManager = Cast<UAstraAssetManager>(GEngine->AssetManager);
	return *AstraAssetManager;
}

void UAstraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FAstraGameplayTags::InitializeNativeGameplayTags();
}

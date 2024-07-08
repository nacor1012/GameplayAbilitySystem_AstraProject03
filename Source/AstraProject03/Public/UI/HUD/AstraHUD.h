// Copyright SkyHigh Gaming.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AstraHUD.generated.h"

class UAstraUserWidget;

UCLASS()
class ASTRAPROJECT03_API AAstraHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<UAstraUserWidget> OverlayWidget;

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAstraUserWidget> OverlayWidgetClass;
	
};

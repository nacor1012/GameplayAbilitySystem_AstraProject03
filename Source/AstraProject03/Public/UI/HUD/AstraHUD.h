// Copyright SkyHigh Gaming.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AstraWidgetController.h"
#include "GameFramework/HUD.h"
#include "AstraHUD.generated.h"

class UOverlayWidgetController;
class UAstraUserWidget;
struct FWidgetControllerParams;

UCLASS()
class ASTRAPROJECT03_API AAstraHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<UAstraUserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAstraUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	
};

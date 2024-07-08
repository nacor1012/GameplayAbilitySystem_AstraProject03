// Copyright SkyHigh Gaming.


#include "UI/HUD/AstraHUD.h"

#include "UI/Widget/AstraUserWidget.h"

void AAstraHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();

}

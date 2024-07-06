// Copyright SkyHigh Gaming.

#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Player/AstraPlayerController.h"

AAstraPlayerController::AAstraPlayerController()
{
	bReplicates = true;
}

void AAstraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AstraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AstraContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);

}

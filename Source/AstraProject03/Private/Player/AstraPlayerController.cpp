// Copyright SkyHigh Gaming.

#include "Player/AstraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"




AAstraPlayerController::AAstraPlayerController()
{
	bReplicates = true;
}

void AAstraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAstraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	/*
	* Line trace from cursor. There are sevral scenarios:
	* A. Lastactor is null && ThisActor is null
	*     - Do nothing
	* B. Lastactor is null && ThisActor is valid
	*     - call Highlight ThisActor
	* C.  Lastactor is valid && ThisActor is null
	*     - call UnHighlight LastActor
	* D. Both actors are valid but LastActor != ThisActor
	*     - Unhighlight Lastactor & Highlight ThisActor
	* E. Both actors are valid and are the same actor
	*     - Do nothing
	*/

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			//Case B
			ThisActor->HighLightActor();
		}
	}
	else //LastActor is valid
	{
		if (ThisActor == nullptr)
		{
			//Case C
			LastActor->UnHighLightActor();
		}
		else // Both actors are valid
		{
			if (LastActor != ThisActor)
			{
				//Case D
				LastActor->UnHighLightActor();
				ThisActor->HighLightActor();
			}
		}
	}
}

void AAstraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AstraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(AstraContext, 0);

	}
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);

}

void AAstraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAstraPlayerController::Move);
}

void AAstraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}



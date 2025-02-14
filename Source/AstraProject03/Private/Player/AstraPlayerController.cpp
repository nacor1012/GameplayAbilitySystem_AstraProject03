// Copyright SkyHigh Gaming.

#include "Player/AstraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Interaction/EnemyInterface.h"
#include "Input/AstraInputComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AstraGameplayTags.h"
#include "Components/SplineComponent.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "DrawDebugHelpers.h"




AAstraPlayerController::AAstraPlayerController()
{
	bReplicates = true;

	Spline = CreateDefaultSubobject<USplineComponent>("Spline");
}

void AAstraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
	AutoRun();

}

void AAstraPlayerController::AutoRun()
{
	if (!bAutoRunning) return;
	if (APawn* ControlledPawn = GetPawn())
	{
		const FVector LocationOnSpline = Spline->FindLocationClosestToWorldLocation(ControlledPawn->GetActorLocation(), ESplineCoordinateSpace::World);
		const FVector Direction = Spline->FindDirectionClosestToWorldLocation(LocationOnSpline, ESplineCoordinateSpace::World);
		ControlledPawn->AddMovementInput(Direction);

		const float DistanceToDestination = (LocationOnSpline - CachedDestination).Length();
		if (DistanceToDestination <= AutoRunAcceptanceRadius)
		{
			bAutoRunning = false;
		}
	}
}

void AAstraPlayerController::CursorTrace()
{
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	if (LastActor != ThisActor)
	{

		if (LastActor) LastActor->UnHighLightActor();
		if (ThisActor) ThisActor->HighLightActor();
	}
}

void AAstraPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
    if (InputTag.MatchesTagExact(FAstraGameplayTags::Get().InputTag_LMB))
	{
		bTargeting = ThisActor ? true : false;
		bAutoRunning = false;
	}
}

void AAstraPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (!InputTag.MatchesTagExact(FAstraGameplayTags::Get().InputTag_LMB))
	{
		if (GetASC()) GetASC()->AbilityInputTagReleased(InputTag);
		return;
	}

	if (bTargeting)
	{
		if (GetASC()) GetASC()->AbilityInputTagReleased(InputTag);
	
	}
	else
	{
		const APawn* ControlledPawn = GetPawn();
		if (FollowTime <= ShortPressThreshold && ControlledPawn)
		{
			if (UNavigationPath* NavPath = UNavigationSystemV1::FindPathToLocationSynchronously(this, ControlledPawn->GetActorLocation(), CachedDestination))
			{
				Spline->ClearSplinePoints();
				for (const FVector& PointLoc : NavPath->PathPoints)
				{
					Spline->AddSplinePoint(PointLoc, ESplineCoordinateSpace::World);
				}

				if (NavPath->PathPoints.Num() > 1)
				{
					CachedDestination = NavPath->PathPoints[NavPath->PathPoints.Num() - 1];
				}
				bAutoRunning = true;
			}

		}
		FollowTime = 0.f;
		bTargeting = false;
	}


}

void AAstraPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
  	if (!InputTag.MatchesTagExact(FAstraGameplayTags::Get().InputTag_LMB))
	{
		if (GetASC()) GetASC()->AbilityInputTagHeld(InputTag);
		return;
	}

	if (bTargeting)
	{
		if (GetASC()) GetASC()->AbilityInputTagHeld(InputTag);
	}
	else
	{
		FollowTime += GetWorld()->GetDeltaSeconds();

		if (CursorHit.bBlockingHit)
		{
			CachedDestination = CursorHit.ImpactPoint;
		}

		if (APawn* ControlledPawn = GetPawn())
		{
			
			const FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
			ControlledPawn->AddMovementInput(WorldDirection);
		}
		
	}
}

UAstraAbilitySystemComponent* AAstraPlayerController::GetASC()
{
	if (AstraAbilitySystemComponent == nullptr)
	{
		AstraAbilitySystemComponent = Cast<UAstraAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	return AstraAbilitySystemComponent;
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

	UAstraInputComponent* AstraInputComponent = CastChecked<UAstraInputComponent>(InputComponent);
	AstraInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAstraPlayerController::Move);
	AstraInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);


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
		bAutoRunning = false;
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}



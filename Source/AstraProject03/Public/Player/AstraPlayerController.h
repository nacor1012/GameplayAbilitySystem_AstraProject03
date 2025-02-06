// Copyright SkyHigh Gaming.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "AbilitySystem/AstraAbilitySystemComponent.h"
#include "AstraPlayerController.generated.h"

class UAstraInputConfig;
class UInputMappingContext;
class UInputAction;
class IEnemyInterface;
class UAstraAbilitySystemComponent;
class USplineComponent;
struct FInputActionValue;

UCLASS()
class ASTRAPROJECT03_API AAstraPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	AAstraPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;


private:

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AstraContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();

	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UAstraInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UAstraAbilitySystemComponent> AstraAbilitySystemComponent;

	UAstraAbilitySystemComponent* GetASC();

	FVector CachedDestination = FVector::ZeroVector;
	float FollowTime = 0.f;
    float ShortPressThreshold = 0.5f;
	bool bAutoRunning = false;
	bool bTargeting = false;

	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius = 50.f;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;

	void AutoRun();
	
};

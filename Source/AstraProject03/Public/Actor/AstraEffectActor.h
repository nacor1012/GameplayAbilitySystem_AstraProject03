// Copyright SkyHigh Gaming.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AstraEffectActor.generated.h"


class USphereComponent;

UCLASS()
class ASTRAPROJECT03_API AAstraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAstraEffectActor();

protected:
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UPROPERTY(EditAnywhere, Category = "Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
};

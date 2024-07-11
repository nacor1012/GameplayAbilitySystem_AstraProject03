// Copyright SkyHigh Gaming.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AstraWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);


struct FOnAttributeChangeData;

UCLASS(BlueprintType, Blueprintable)
class ASTRAPROJECT03_API UOverlayWidgetController : public UAstraWidgetController
{
	GENERATED_BODY()

public:

	virtual void BroadcastInitialValues() override;

	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;

protected:

	void HealthChanged(const FOnAttributeChangeData& Data) const;
    void MaxHealthChanged(const FOnAttributeChangeData& Data) const; 
	
};

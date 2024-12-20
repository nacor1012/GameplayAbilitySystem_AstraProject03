// Copyright SkyHigh Gaming.

#pragma once

#include "AbilitySystem/Data/AttributeInfo.h"
#include "CoreMinimal.h"
#include <AttributeSet.h>
#include "UI/WidgetController/AstraWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"


class UAttributeInfo;
struct FAstraAttributeInfo;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeInfoSignature, const FAstraAttributeInfo&, Info);

/**
 * 
 */

UCLASS(BlueprintType, Blueprintable)
class ASTRAPROJECT03_API UAttributeMenuWidgetController : public UAstraWidgetController
{
	GENERATED_BODY()

public:

	virtual void BindCallbacksToDependencies() override;
	virtual void BroadcastInitialValues() override;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FAttributeInfoSignature AttributeInfoDelegate;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UAttributeInfo> AttributeInfo;

private:

	void BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const ;
	
};

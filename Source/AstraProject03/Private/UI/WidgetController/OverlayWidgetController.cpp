// Copyright SkyHigh Gaming.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AstraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{

	const UAstraAttributeSet* AstraAttributeSet = CastChecked<UAstraAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(AstraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AstraAttributeSet->GetMaxHealth());
		
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAstraAttributeSet* AstraAttributeSet = CastChecked<UAstraAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AstraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AstraAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

// Copyright SkyHigh Gaming.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AstraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{

	const UAstraAttributeSet* AstraAttributeSet = CastChecked<UAstraAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(AstraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AstraAttributeSet->GetMaxHealth());


		
}

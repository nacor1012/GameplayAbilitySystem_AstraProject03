// Copyright SkyHigh Gaming.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AstraAbilitySystemComponent.h"
#include "AbilitySystem/AstraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{

	const UAstraAttributeSet* AstraAttributeSet = CastChecked<UAstraAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(AstraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AstraAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(AstraAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(AstraAttributeSet->GetMaxMana());
		
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAstraAttributeSet* AstraAttributeSet = CastChecked<UAstraAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AstraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AstraAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AstraAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AstraAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);

	Cast<UAstraAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags) 
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				//Converts converts the gameplay tag to a string the *before tag converts the string to an array to Tcars
				const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg);

<<<<<<< HEAD
				FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
=======
				FUIWidgetRow Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
>>>>>>> d92e3f03ca49e8fb51ae594bfc84945dd0fec63c
			}
		});

}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}

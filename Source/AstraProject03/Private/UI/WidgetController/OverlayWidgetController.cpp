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

				//"TagGroup.Tag" .MatchesTag("TagGroup") will return true, "TagGroup".MatchesTag("TagGroup.Tag") will return false
				// so in this function we are passing in the Tag veriable and .MatchesTag to "Message" so anything with Message as in its tag will show up
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
	               const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
				   MessageWidgetRow.Broadcast(*Row);
				}

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

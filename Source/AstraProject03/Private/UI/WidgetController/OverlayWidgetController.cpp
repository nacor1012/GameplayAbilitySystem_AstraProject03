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

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AstraAttributeSet->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue); 
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AstraAttributeSet->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data) 
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue); 
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AstraAttributeSet->GetManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data) 
		{
			OnManaChanged.Broadcast(Data.NewValue); 
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AstraAttributeSet->GetMaxManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data) 
		{
			OnMaxManaChanged.Broadcast(Data.NewValue); 
		}
	);

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
		}
	);

}

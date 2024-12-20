// Copyright SkyHigh Gaming.


#include "AbilitySystem/Data/AttributeInfo.h"

FAstraAttributeInfo UAttributeInfo::FindAttributeInfoTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FAstraAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't fine Into for AttributeTag [%s] on AttributeInfo [%s] ."), *AttributeTag.ToString(), *GetNameSafe(this));
	}

	return FAstraAttributeInfo();
}

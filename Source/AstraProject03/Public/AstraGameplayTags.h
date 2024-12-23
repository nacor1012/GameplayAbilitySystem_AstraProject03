// Copyright SkyHigh Gaming.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * AstraGameplayTags
 * 
 * Singleton Containing the native Gameplay Tags
 */

struct FAstraGameplayTags
{
public:
	static const FAstraGameplayTags& Get() { return GameplayTags;}
	static void InitializeNativeGameplayTags();

	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Dexterity;
	FGameplayTag Attributes_Primary_Agility;
	FGameplayTag Attributes_Primary_Stamina;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Wisdom;
	FGameplayTag Attributes_Primary_Charisma;

	FGameplayTag Attributes_Secondary_ArmorClass;
	FGameplayTag Attributes_Secondary_ArmorPenetration;
	FGameplayTag Attributes_Secondary_BlockChance;
	FGameplayTag Attributes_Secondary_CriticalHitChance;
	FGameplayTag Attributes_Secondary_CriticalHitDamage;
	FGameplayTag Attributes_Secondary_CriticalHitResistance;
	FGameplayTag Attributes_Secondary_HealthRegeneration;
	FGameplayTag Attributes_Secondary_ManaRegeneration;
	FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_MaxMana;

	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;
	FGameplayTag InputTag_5;
	FGameplayTag InputTag_6;
	FGameplayTag InputTag_7;
	FGameplayTag InputTag_8;
	FGameplayTag InputTag_9;

private:
	static FAstraGameplayTags GameplayTags;
};
// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAttributeSet.h"

UPlayerAttributeSet::UPlayerAttributeSet()
{
}

void UPlayerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
}

void UPlayerAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
}

void UPlayerAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
}

void UPlayerAttributeSet::OnRep_Hunger(const FGameplayAttributeData& OldHunger)
{
}

void UPlayerAttributeSet::OnRep_Thirst(const FGameplayAttributeData& OldThirst)
{
}

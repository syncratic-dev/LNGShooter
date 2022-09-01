// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "LNGShooter.h"

#include "Chop_GameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class LNGSHOOTER_API UChop_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UChop_GameplayAbility();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	AbilityInputID AbilityInputID = AbilityInputID::None;
};

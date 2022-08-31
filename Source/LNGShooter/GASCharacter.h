// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <AbilitySystemInterface.h>
#include <GameplayEffectTypes.h>
#include "PlayerAbilitySystemComponent.h"
#include "PlayerAttributeSet.h"
#include "Chop_GameplayAbility.h"

#include "GASCharacter.generated.h"

UCLASS()
class LNGSHOOTER_API AGASCharacter : public ACharacter, public IAbilitySystemInterface
{
public:
	AGASCharacter();
	
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera; 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	class UPlayerAbilitySystemComponent* AbilitySystemComponent; 

	UPROPERTY()
	class UPlayerAttributeSet* Attributes;
	

public:
	// Sets default values for this character's properties
	virtual void InitializeAttributes();
	virtual void GiveAbilities();

	virtual void PossessedBy(AController* newController) override; 
	virtual void OnRep_PlayerState() override; 

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Abilities)
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Abilities)
	TArray<TSubclassOf<UChop_GameplayAbility>> DefaultAbilities; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	class UAbilitySystemComponent* GetAbilitySystemComponent() const override; 

};

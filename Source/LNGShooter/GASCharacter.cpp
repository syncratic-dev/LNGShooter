// Fill out your copyright notice in the Description page of Project Settings.


#include "GASCharacter.h"
#include "ItemBase.h"
#include "InventoryComponent.h"


void AGASCharacter::InitializeAttributes()
{
	if (!AbilitySystemComponent || !DefaultAttributeEffect)
		return; 

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1, EffectContext);

	if (SpecHandle.IsValid())
	{
		FActiveGameplayEffectHandle GEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}

void AGASCharacter::GiveAbilities()
{
	if (HasAuthority() && AbilitySystemComponent)
	{
		for (TSubclassOf<UChop_GameplayAbility>& StartupAbility : DefaultAbilities)
		{
			AbilitySystemComponent->GiveAbility(
				FGameplayAbilitySpec(
					StartupAbility,
					1,
					(uint32)StartupAbility.GetDefaultObject()->AbilityInputID,
					this));
		}
	}
}

void AGASCharacter::UseItem(UItemBase* Item)
{
	if (!Item) return;

	Item->OnUse(this);
}


void AGASCharacter::PossessedBy(AController* newController)
{
	Super::PossessedBy(newController);

	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	InitializeAttributes();
	GiveAbilities();
}

void AGASCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	InitializeAttributes();

	if (AbilitySystemComponent && InputComponent)
	{
		const FGameplayAbilityInputBinds Binds("Confirm", "Cancel", "EGASAbilityInputID", (int32)AbilityInputID::Confirm, (int32)AbilityInputID::Cancel);
		AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, Binds);
	}
}

// Sets default values
AGASCharacter::AGASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UPlayerAbilitySystemComponent>("AbilitySystemComp");

	if (!AbilitySystemComponent) return; 

	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	Attributes = CreateDefaultSubobject<UPlayerAttributeSet>("Attributes");

	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");
	Inventory->Capacity = 20; 
}

// Called when the game starts or when spawned
void AGASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (AbilitySystemComponent && InputComponent)
	{
		const FGameplayAbilityInputBinds Binds("Confirm", "Cancel", "AbilityInputID", (uint32)AbilityInputID::Confirm, (uint32)AbilityInputID::Cancel);
		AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, Binds);
	}
}

UAbilitySystemComponent* AGASCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// TODO MOHAMMAD: Finish rest of the video. Left off at 22 minutes. https://www.youtube.com/watch?v=Yub52f4ZUU0&t=620s
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemBase.h"

#include "InventoryComponent.generated.h"

// Blueprints will bind to this to update UI
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LNGSHOOTER_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	virtual void BeginPlay() override; 

	bool AddItem(class UItemBase* Item);
	bool RemoveItem(class UItemBase* Item);

	UPROPERTY(EditDefaultsOnly, Instanced)
	TArray<class UItemBase*> DefaultItems; 

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	int32 Capacity; 

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryUpdated OnInventoryUpdated; 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
	TArray<class UItemBase*> Items; 

		
};

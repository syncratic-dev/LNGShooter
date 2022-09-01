// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	Capacity = 20; 
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	for (auto& Item : DefaultItems)
	{
		AddItem(Item);
	}
	
}

bool UInventoryComponent::AddItem(UItemBase* Item)
{
	// Capacity / null check 
	if (Items.Num() >= Capacity || !Item) return false;  

	Item->OwningInventory = this; 
	Item->World = GetWorld();
	Items.Add(Item);

	// Update UI
	OnInventoryUpdated.Broadcast();

	return true; 
}

bool UInventoryComponent::RemoveItem(UItemBase* Item)
{
	if (Item)
	{
		Item->OwningInventory = nullptr; 
		Item->World = nullptr; 
		Items.RemoveSingle(Item);

		OnInventoryUpdated.Broadcast();
		return true; 
	}
	return false; 
}

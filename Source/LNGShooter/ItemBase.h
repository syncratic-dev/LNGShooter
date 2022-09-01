// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemBase.generated.h"

/**
 *
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class LNGSHOOTER_API UItemBase : public UObject
{
	GENERATED_BODY()

public:
	UItemBase();

	// World 
	UPROPERTY(Transient)
		class UWorld* World; 

	virtual class UWorld* GetWorld() const { return World; }

	// Text for using it (Equip, eat, etc.) 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText UseActionText;

	// Mesh to display for this items pickup 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		class UStaticMesh* PickupMesh;

	// Thumbnail for this item 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		class UTexture2D* Thumbnail;

	// Display name for item in inventory
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText ItemDisplayName;

	// Optional description for item 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
		FText ItemDescription;

	// Weight of item 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
		float Weight;

	UPROPERTY()
		class UInventoryComponent* OwningInventory;

	UFUNCTION(BlueprintImplementableEvent)
		void OnUse(class AGASCharacter* Character);
};

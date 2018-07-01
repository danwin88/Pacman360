// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupBase.h"
#include "GoalPickup.generated.h"

/**
 * A tipe of pickup that have a score value 
 */
UCLASS()
class GEARVRGAME_API AGoalPickup : public APickupBase
{
	GENERATED_BODY()
	
public:
	AGoalPickup();

	void OnGetCollected_Implementation() override;

	float GetGoalValue();
protected:
	//GoalValue
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Goals", meta = (BlueprintProtected = "true"))
		float GoalValue;
	
	
};

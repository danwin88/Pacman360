// Fill out your copyright notice in the Description page of Project Settings.

#include "GoalPickup.h"

AGoalPickup::AGoalPickup() {
	GoalValue = 100.0f;
}
//UFUNCTION(BlueprintCallable, Category = Pickup)
void AGoalPickup::OnGetCollected_Implementation() {
	Super::OnGetCollected_Implementation();
	Destroy();
}

float AGoalPickup::GetGoalValue() {
	return GoalValue;
}
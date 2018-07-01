// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PacmanPawn.generated.h"

UCLASS()
class GEARVRGAME_API APacmanPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APacmanPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* Mesh;
	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UCapsuleComponent* Capsule;
	UPROPERTY(VisibleDefaultsOnly, Category = Score)
		float Score = 0.0f;
	UPROPERTY(VisibleDefaultsOnly, Category = Score)
		float CollectedGoals = 0.0f;

public:	
	// Called every frame
	void Tick(float DeltaTime) override;
	float GetScore() {
		return Score;
	}
	float GetNumGoals() {
		return CollectedGoals;
	}
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OnCollectPickup();
	
	
};

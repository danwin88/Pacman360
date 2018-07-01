// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class GEARVRGAME_API AEnemy : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Triggers, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* bodySphereTrigger;

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//The health of the enemy
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy  Behavior")
		bool bCanTakeDamage;
	//check if the enemy is dead or alive
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Behavior")
		bool IsDead;
	//Check if the enemy is Attacking
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Behavior") 
		bool IsAttacking;
	/* This can be used for new types of Ghosts or dynamics Ej: Lightnig 
	//The sensing component used to see or hear the player
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy AI")
		class UPawnSensingComponent* PawnSensor;
	//Hear the player's noise using the sensing component
	UFUNCTION()
	void OnHearNoise(APawn *OtherActor, constFVector&Location, float
	Volume);
	//See the player's by sight using the sensing component
	UFUNCTION()
	void OnSeePawn(APawn *OtherPawn);
	*/
	//The used BT with that enemy
	/*
	UFUNCTION(BlueprintCallable)
		void SetCanTakeDamage(bool NewState);

	UFUNCTION(BlueprintCallable)
		bool GetCanTakeDamage();
	*/
	UPROPERTY(EditAnywhere, Category = "Enemy AI")
		class UBehaviorTree* EnemyBehaviorTree;
	//Score of the enemy, default 100
	UPROPERTY(EditAnywhere, Category = "Score")
		int32 Score = 100;
	UFUNCTION(BlueprintCallable, Category = Behavior)
		void OnTriggerOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION(BlueprintCallable, Category = Score)
		int32 GetScore();
	FORCEINLINE class USphereComponent* GetBodySphereTrigger() const {
		return bodySphereTrigger;
	}
};

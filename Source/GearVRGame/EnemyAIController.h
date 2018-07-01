// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class GEARVRGAME_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
protected:
	int32 EnemyKeyID;
	int32 EnemyPositionKeyID;
public:
	AEnemyAIController();
	UPROPERTY(Transient)
		UBlackboardComponent* BlackboardComp;

	UPROPERTY(Transient)
		UBehaviorTreeComponent* BehaviorComp;
	virtual void Possess(class APawn* InPawn) override;

	//virtual void BeginInactiveState() override;

	UFUNCTION(BlueprintCallable, Category = Behavior)
		void SetEnemy(class APawn* InPawn);
	
	UFUNCTION(BlueprintCallable, Category = Behavior)
		class APacmanPawn* GetEnemy() const;
	UFUNCTION(BlueprintCallable, Category = Behaviour)
		void UpdateControlRotation(float DeltaTime, bool bUpdatePawn);
	UFUNCTION(BlueprintCallable, Category = Behaviour)
		void OnSearchForEnemy();
};

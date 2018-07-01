// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"
#include "Enemy.h"
#include "PacmanPawn.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/BlackboardComponent.h"

AEnemyAIController::AEnemyAIController() {
	BlackboardComp = CreateAbstractDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoardComp"));
	BehaviorComp = CreateAbstractDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));

	bWantsPlayerState = true;
}


void AEnemyAIController::Possess(APawn* InPawn) {
	Super::Possess(InPawn);
	AEnemy* _tempEnemy = Cast<AEnemy>(InPawn);
	// start behavior
	if (_tempEnemy && _tempEnemy->EnemyBehaviorTree ) { 
		BlackboardComp->InitializeBlackboard(*_tempEnemy->EnemyBehaviorTree->BlackboardAsset);

		//Get the blackboard ID and store it to acess later
		EnemyKeyID = BlackboardComp->GetKeyID("Enemy");
		EnemyPositionKeyID = BlackboardComp->GetKeyID("EnemyPosition");

		BehaviorComp->StartTree(*_tempEnemy->EnemyBehaviorTree);
		UE_LOG(LogClass, Log, TEXT("Got the Enemy and BT have been started"));
	}
}
void AEnemyAIController::SetEnemy(class APawn* InPawn)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValue<UBlackboardKeyType_Object>(EnemyKeyID,InPawn);
		BlackboardComp->SetValueAsVector(BlackboardComp->GetKeyName(EnemyPositionKeyID), InPawn->GetActorLocation());
		SetFocus(InPawn);
	}
}

class APacmanPawn* AEnemyAIController::GetEnemy() const
{
	if (BlackboardComp)
	{
		return Cast<APacmanPawn>(BlackboardComp->GetValue<UBlackboardKeyType_Object>(EnemyKeyID));
	} 
	return NULL;
}

void AEnemyAIController::UpdateControlRotation(float DeltaTime, bool bUpdatePawn)
{
	// Look toward focus
	FVector TheCenter = GetFocalPoint();
	if (!TheCenter.IsZero() && GetPawn())
	{
		FVector Direction = TheCenter - GetPawn()->GetActorLocation();
		FRotator TheNewRotation = Direction.Rotation();
		TheNewRotation.Yaw = FRotator::ClampAxis(TheNewRotation.Yaw);
		SetControlRotation(TheNewRotation);
		APawn* const _tempPawn = GetPawn();
		if (_tempPawn &&bUpdatePawn)
		{
			_tempPawn->FaceRotation(TheNewRotation, DeltaTime);
		}
	}
}

void AEnemyAIController::OnSearchForEnemy()
{
	APawn* _tempPawn = GetPawn();
	if (_tempPawn == NULL)
	{
		return;
	}
	const FVector _tempLocation = _tempPawn->GetActorLocation();
	float BestDistSq = MAX_FLT;
	APacmanPawn* PlayerPawn = NULL;
	//foreach all pawns in world
	for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It;
		++It)
	{

		APacmanPawn* TestPawn = Cast<APacmanPawn>(*It);
		AEnemy* const _testEnemy = Cast<AEnemy>(TestPawn);
		if (_testEnemy)
		{
			//it is just another enemy, not player, can be usefull to know where are the others
		}
		else
		{
			if (TestPawn)
			{
				UE_LOG(LogClass, Log, TEXT(" ===================>>>>> ENEMY SEEN "));
				const float _distanceSq = (TestPawn->GetActorLocation() - _tempLocation).SizeSquared();
				if (_distanceSq < BestDistSq)
				{
					BestDistSq = _distanceSq;
					PlayerPawn = TestPawn;
				}
			}
		}
		
	}
	if (PlayerPawn)
	{
		// We saw someone, so set him as target.
		SetEnemy(PlayerPawn);
		UE_LOG(LogClass, Log, TEXT(" ===================>>>>> Set Target"));
	}
}
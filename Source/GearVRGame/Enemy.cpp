// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "EnemyAIController.h"
#include "PacmanPawn.h"
#include "Components/SphereComponent.h"
//#include "Perception\PawnSensingComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set the AI controller Class
	AIControllerClass = AEnemyAIController::StaticClass();

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	bCanTakeDamage = false;
	IsDead = false;
	IsAttacking = false;

	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = true;
	bUseControllerRotationRoll = true;
	/*
	bodySphereTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger Sphere"));
	bodySphereTrigger->SetSphereRadius(40.f);
	bodySphereTrigger->SetupAttachment(RootComponent);
	*/
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::OnTriggerOverlap(class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	APacmanPawn* const _tempPacman = Cast<APacmanPawn>(OtherActor);
	if (_tempPacman)
	{
		FString message = TEXT("=== HIT PLAYER, GAME MUST BE ENDED ==== ");
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, message);
		//in case it hit the player end the game
	}
}
int32 AEnemy::GetScore() {
	return Score;
}

/*
bool AEnemy::GetCanTakeDamage() {
	return bCanTakeDamage;

}
void AEnemy::SetCanTakeDamage(bool NewState) {
	bCanTakeDamage = NewState;
}*/
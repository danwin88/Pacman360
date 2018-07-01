// Fill out your copyright notice in the Description page of Project Settings.

#include "PacmanPawn.h"
#include "Components/CapsuleComponent.h"
#include "PickupBase.h"
#include "GoalPickup.h"
// Sets default values
APacmanPawn::APacmanPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APacmanPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APacmanPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	OnCollectPickup();
}

// Called to bind functionality to input
void APacmanPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APacmanPawn::OnCollectPickup() {
	//will be destroyed in the fututre
	TArray<AActor*> CollectedPickups;

	Capsule->GetOverlappingActors(CollectedPickups);
	//loop
	for (int32 c = 0; c < CollectedPickups.Num(); c++) {
		APickupBase * const _tempPickup = Cast<APickupBase>(CollectedPickups[c]);
		if (_tempPickup && !_tempPickup->IsPendingKill() && _tempPickup->IsActive()) {
			_tempPickup->OnGetCollected();
			AGoalPickup * const _tempGoal = Cast<AGoalPickup>(_tempPickup);
			if (_tempGoal) {
				Score += _tempGoal->GetGoalValue();
				CollectedGoals += 1;
				_tempPickup->SetActive(false);
			}
		}
	}
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupBase.h"

// Sets default values
APickupBase::APickupBase()
{
 	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = false;
	bIsActive = true;
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("PickupRoot"));
	PickupMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// is active the pickup?
bool APickupBase::IsActive() {
	return bIsActive;
}

// the core thing
void APickupBase::OnGetCollected_Implementation() {

}
// Set the state of the pickup
void APickupBase::SetActive(bool Newstate) {
	bIsActive = Newstate;
}

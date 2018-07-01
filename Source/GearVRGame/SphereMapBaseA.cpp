// Fill out your copyright notice in the Description page of Project Settings.

#include "SphereMapBaseA.h"
#include "PositionVertexBuffer.h"
#include "GearVRCharacter.h"


ASphereMapBaseA::ASphereMapBaseA(const FObjectInitializer& Objectinititializer) :Super(Objectinititializer)
{

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent0"));
	RootComponent = MeshRootComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent0"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetCollisionProfileName("BlockAll");
}



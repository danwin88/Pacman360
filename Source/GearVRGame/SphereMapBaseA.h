// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "SphereMapBaseA.generated.h"






UCLASS()
class GEARVRGAME_API ASphereMapBaseA : public AActor
{
	GENERATED_BODY()

public:


	/**
	* Default UObject constructor.
	*/
	ASphereMapBaseA(const FObjectInitializer& Objectinititializer = FObjectInitializer::Get());


private:

	/** The root component of the Mesh*/
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Ball, meta = (AllowPrivateAccess = "true"))
		USceneComponent* MeshRootComponent;

	/**Mesh MeshComponet*/
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Ball, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* MeshComponent;
public:
	/** Returns Ball subobject **/
	FORCEINLINE class UStaticMeshComponent* GetMeshMesh() const { return MeshComponent; }
	/** Returns MeshRootComponent subobject **/
	FORCEINLINE class USceneComponent* GetMeshRootComponent() const { return MeshRootComponent; }

};

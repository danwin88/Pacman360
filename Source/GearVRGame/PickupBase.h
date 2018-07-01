// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupBase.generated.h"

UCLASS()
class GEARVRGAME_API APickupBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickups", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* PickupMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickups", meta = (AllowPrivateAccess = "true"))
		bool bIsActive;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE class UStaticMeshComponent* GetMesh() const {
		return PickupMesh;
	}
	//to handle the collection
	UFUNCTION(BlueprintPure, Category = "Pickups")
		bool IsActive();
	UFUNCTION(BlueprintCallable, Category = "Pickups")
		void SetActive(bool NewPickupState);
	
	//when the pickup is collected this function are called
	UFUNCTION(BlueprintNativeEvent)
		void OnGetCollected();
	virtual void OnGetCollected_Implementation();
	
};

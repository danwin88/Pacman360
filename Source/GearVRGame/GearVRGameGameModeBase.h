// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GearVRGameGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class GEARVRGAME_API AGearVRGameGameModeBase : public AGameMode
{
	GENERATED_BODY()

	virtual void StartPlay() override;

};

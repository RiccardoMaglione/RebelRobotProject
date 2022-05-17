// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RR_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class REBELROBOT_API URR_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | GameInstance")
	FString LevelOfReturn;
	
};

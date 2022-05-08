// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RR_Ability_ActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class REBELROBOT_API URR_Ability_ActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URR_Ability_ActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Cooldown_Dash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Cooldown_Shield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Cooldown_BlackHole;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Cooldown_ShockWave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Temp_CD_Dash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Temp_CD_Shield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Temp_CD_BlackHole;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Temp_CD_ShockWave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		bool bAC_CanLaunch_Dash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		bool bAC_CanLaunch_Shield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		bool bAC_CanLaunch_BlackHole;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		bool bAC_CanLaunch_ShockWave;
};

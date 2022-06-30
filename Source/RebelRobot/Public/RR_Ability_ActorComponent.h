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
		float fAC_Cooldown_Dash = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Cooldown_Shield = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Cooldown_BlackHole = 15.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Cooldown_ShockWave = 4.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Temp_CD_Dash = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Temp_CD_Shield = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Temp_CD_BlackHole = 15.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		float fAC_Temp_CD_ShockWave = 4.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		bool bAC_CanLaunch_Dash = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		bool bAC_CanLaunch_Shield = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		bool bAC_CanLaunch_BlackHole = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		bool bAC_CanLaunch_ShockWave = true;



	UFUNCTION(BlueprintCallable, Category = "RR | Ability")
		float Func_Ability_ShockWave(TSubclassOf<AActor> WaveAreaLarge, TSubclassOf<AActor> WaveAreaSmall);

	UFUNCTION(BlueprintCallable, Category = "RR | Ability")
		float Func_Ability_BlackHole(FTransform SpawnTransform, TSubclassOf<AActor> BlackHoleProjectile);

	UFUNCTION(BlueprintCallable, Category = "RR | Ability")
		float Func_Ability_Shield(TSubclassOf<AActor> BPShield);
};

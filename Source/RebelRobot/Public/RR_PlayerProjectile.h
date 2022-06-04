// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RR_PlayerProjectile.generated.h"

UCLASS()
class REBELROBOT_API ARR_PlayerProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARR_PlayerProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | PlayerProjectile")
		float Var_SpeedProjectile;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | PlayerProjectile")
		float Var_Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | PlayerProjectile")
		FVector Var_ScaleAOE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | PlayerProjectile")
		float Var_TimerDestroyFromBegin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | PlayerProjectile")
		float Var_DamageAOE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | PlayerProjectile")
		float Var_IsPenetrationProjectile;
};

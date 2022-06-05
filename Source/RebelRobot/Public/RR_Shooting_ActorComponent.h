// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Engine.h"
#include "RR_CameraComponent.h"
#include "RR_PlayerProjectile.h"
#include "FMODBlueprintStatics.h"
#include "Animation/AnimInstance.h"
#include "RR_PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "FMODEvent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RR_Shooting_ActorComponent.generated.h"



USTRUCT(BlueprintType)
struct FWeaponStructCode
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		FName NameWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		bool IsAutomaticWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		int ProjectileDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		int AmmoConsumePerShoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		int MaxProjectilePerBarrage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		int MaxProjectilePerMagazine;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		int MaxProjectileInWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		int ActualProjectileInBarrage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		int ActualProjectileInMagazine;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		int ActualProjectileInWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		float DelayBetweenSingleShot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		float DelayBetweenBarrage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		float DelayBetweenMagazine;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		float ProjectileSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		bool IsShotgun;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		float ShotgunProjectileSpeedDifference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		float ShotgunSpread;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		bool IsChargedWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		float ChargeTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		float MaxChargedDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		float Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		float Imprecision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		int NumberOfProjectileInSingleShotgun;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		FVector ScaleAOE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		float TimerDestroyProjectileFromBegin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		float DamageAOE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		TSubclassOf<ARR_PlayerProjectile> PlayerBullet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		AActor* EnemyBullet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		UFMODEvent* FModEventSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		bool IsPenetrationBullet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		bool CanUseWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		int RechargeProjectileInWeapon;
};



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class REBELROBOT_API URR_Shooting_ActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URR_Shooting_ActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		TArray<FWeaponStructCode> WSC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		bool CanShoot = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		bool InRecharge;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		bool CanResetBarrage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		bool IsPressedWeaponKey;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		bool IsLoop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		bool CanShootAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		UAnimMontage* MontageToPlay_Recharge;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		UFMODEvent* FModEventRechargeSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		UFMODEvent* FModEventRifle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Shooting | Struct")
		TSubclassOf<UCameraShakeBase> shakeCam;


	UFUNCTION(BlueprintCallable, Category = "RR | Shooting")
		void Func_Shotgun(int IndexWeaponStruct, USkeletalMeshComponent* meshPlayer, URR_CameraComponent* CamComp);
	UFUNCTION(BlueprintCallable, Category = "RR | Shooting")
		void Func_Normal(int IndexWeaponStruct, URR_CameraComponent* CamComp);
	UFUNCTION(BlueprintCallable, Category = "RR | Shooting")
		void Func_TypeShooting(int IndexWeaponStruct, USkeletalMeshComponent* meshPlayer, URR_CameraComponent* CamComp);
	UFUNCTION(BlueprintCallable, Category = "RR | Shooting")
		void Func_DecreaseAmmo(int IndexWeaponStruct);
	UFUNCTION(BlueprintCallable, Category = "RR | Shooting")
		void Func_ShootingProjectileV2(int IndexWeaponStruct, USkeletalMeshComponent* meshPlayer, URR_CameraComponent* CamComp);




	UFUNCTION(BlueprintCallable, Category = "RR | Shooting")
		void Func_ResetActualProjectileInBarrage(int IndexWeaponStruct);		//Controllare se lasciarlo in tick o utilizzare un observer
	UFUNCTION(BlueprintCallable, Category = "RR | Shooting")
		void Func_FirstPartOfShooting(int IndexWeaponStruct, USkeletalMeshComponent* meshPlayer, URR_CameraComponent* CamComp);					//Controllare se lasciarlo in tick o utilizzare un observer


	UFUNCTION(BlueprintCallable, Category = "RR | Shooting")
		void Func_ChooseRecharge(int IndexWeaponStruct, bool InTick, bool InPress);
	UFUNCTION(BlueprintCallable, Category = "RR | Shooting")
		void Func_Recharge(int IndexWeaponStruct);
};
// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_Shooting_ActorComponent.h"

// Sets default values for this component's properties
URR_Shooting_ActorComponent::URR_Shooting_ActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//Func_FirstPartOfShooting();
	//Func_ResetActualProjectileInBarrage();
	// ...
}


// Called when the game starts
void URR_Shooting_ActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	

	for (size_t i = 0; i < WSC.Num(); i++)
	{
		WSC[i].ActualProjectileInMagazine = WSC[i].MaxProjectilePerMagazine;
		WSC[i].ActualProjectileInWeapon = WSC[i].MaxProjectileInWeapon;
	}
}


// Called every frame
void URR_Shooting_ActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URR_Shooting_ActorComponent::Func_Shotgun(int IndexWeaponStruct, USkeletalMeshComponent* meshPlayer, URR_CameraComponent* CamComp)
{
	if (WSC[IndexWeaponStruct].FModEventSound) {
		FFMODEventInstance TempInstFMOD = UFMODBlueprintStatics::PlayEvent2D(GetWorld(), WSC[IndexWeaponStruct].FModEventSound, true); //PlayEvent2D Fmod
	}

	const FVector InitialLocation = meshPlayer->GetComponentLocation();
	const FRotator InitialiRotation = FRotator(0.0f, meshPlayer->GetComponentRotation().Yaw - WSC[IndexWeaponStruct].ShotgunSpread, meshPlayer->GetComponentRotation().Roll);
	ARR_PlayerProjectile* tempProjectile = GetWorld()->SpawnActor<ARR_PlayerProjectile>(WSC[IndexWeaponStruct].PlayerBullet, InitialLocation, InitialiRotation, FActorSpawnParameters());
	tempProjectile->Var_SpeedProjectile = FMath::RandRange(WSC[IndexWeaponStruct].ShotgunProjectileSpeedDifference, WSC[IndexWeaponStruct].ProjectileSpeed);
	tempProjectile->Var_Damage = WSC[IndexWeaponStruct].Damage;
	tempProjectile->Var_ScaleAOE = WSC[IndexWeaponStruct].ScaleAOE;
	tempProjectile->Var_TimerDestroyFromBegin = WSC[IndexWeaponStruct].TimerDestroyProjectileFromBegin;
	tempProjectile->Var_DamageAOE = WSC[IndexWeaponStruct].DamageAOE;
	tempProjectile->Var_IsPenetrationProjectile = WSC[IndexWeaponStruct].IsPenetrationBullet;

	const FVector InitialLocation1 = meshPlayer->GetComponentLocation();
	const FRotator InitialiRotation1 = FRotator(0.0f, meshPlayer->GetComponentRotation().Yaw + WSC[IndexWeaponStruct].ShotgunSpread, meshPlayer->GetComponentRotation().Roll);
	ARR_PlayerProjectile* tempProjectile1 = GetWorld()->SpawnActor<ARR_PlayerProjectile>(WSC[IndexWeaponStruct].PlayerBullet, InitialLocation1, InitialiRotation1, FActorSpawnParameters());
	tempProjectile1->Var_SpeedProjectile = FMath::RandRange(WSC[IndexWeaponStruct].ShotgunProjectileSpeedDifference, WSC[IndexWeaponStruct].ProjectileSpeed);
	tempProjectile1->Var_Damage = WSC[IndexWeaponStruct].Damage;
	tempProjectile1->Var_ScaleAOE = WSC[IndexWeaponStruct].ScaleAOE;
	tempProjectile1->Var_TimerDestroyFromBegin = WSC[IndexWeaponStruct].TimerDestroyProjectileFromBegin;
	tempProjectile1->Var_DamageAOE = WSC[IndexWeaponStruct].DamageAOE;
	tempProjectile1->Var_IsPenetrationProjectile = WSC[IndexWeaponStruct].IsPenetrationBullet;
	
	for (size_t i = 0; i < WSC[IndexWeaponStruct].NumberOfProjectileInSingleShotgun; i++)
	{
		//spawn system at location
		FVector Loc = CamComp->GetComponentLocation();
		UGameplayStatics::PlayWorldCameraShake(GetWorld(), shakeCam, Loc, 100.0f, 1000.0f);

		const FVector InitialLocation2 = meshPlayer->GetComponentLocation();
		const FRotator InitialiRotation2 = FRotator(0.0f, FMath::RandRange(meshPlayer->GetComponentRotation().Yaw - WSC[IndexWeaponStruct].ShotgunSpread, meshPlayer->GetComponentRotation().Yaw + WSC[IndexWeaponStruct].ShotgunSpread), meshPlayer->GetComponentRotation().Roll);
		ARR_PlayerProjectile* tempProjectile2 = GetWorld()->SpawnActor<ARR_PlayerProjectile>(WSC[IndexWeaponStruct].PlayerBullet, InitialLocation2, InitialiRotation2, FActorSpawnParameters());
		tempProjectile2->Var_SpeedProjectile = FMath::RandRange(WSC[IndexWeaponStruct].ShotgunProjectileSpeedDifference, WSC[IndexWeaponStruct].ProjectileSpeed);
		tempProjectile2->Var_Damage = WSC[IndexWeaponStruct].Damage;
		tempProjectile2->Var_ScaleAOE = WSC[IndexWeaponStruct].ScaleAOE;
		tempProjectile2->Var_TimerDestroyFromBegin = WSC[IndexWeaponStruct].TimerDestroyProjectileFromBegin;
		tempProjectile2->Var_DamageAOE = WSC[IndexWeaponStruct].DamageAOE;
		tempProjectile2->Var_IsPenetrationProjectile = WSC[IndexWeaponStruct].IsPenetrationBullet;
	}


}

void URR_Shooting_ActorComponent::Func_Normal(int IndexWeaponStruct, URR_CameraComponent* CamComp)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Passa")));
	if (WSC[IndexWeaponStruct].FModEventSound) {
		FFMODEventInstance TempInstFMOD = UFMODBlueprintStatics::PlayEvent2D(GetWorld(), WSC[IndexWeaponStruct].FModEventSound, true); //PlayEvent2D Fmod
		if (WSC[IndexWeaponStruct].FModEventSound == FModEventRifle) {
			UFMODBlueprintStatics::EventInstanceSetParameter(TempInstFMOD, "Stop_Weapon", 1.0f);
		}
	}	
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Passa 1")));
	//Spawn System at Location
	FVector Loc = CamComp->GetComponentLocation();
	UGameplayStatics::PlayWorldCameraShake(GetWorld(), shakeCam, Loc, 100.0f, 1000.0f);
	
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Passa 2")));

	const FVector InitialLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetMesh()->GetComponentLocation();
	float zLoc = FMath::RandRange(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetMesh()->GetComponentRotation().Yaw - WSC[IndexWeaponStruct].Imprecision, UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetMesh()->GetComponentRotation().Yaw + WSC[IndexWeaponStruct].Imprecision);
	const FRotator InitialiRotation = FRotator(0.0f, zLoc, UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetMesh()->GetComponentRotation().Roll);

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("x = %f e z = %f"), UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetMesh()->GetComponentRotation().Roll, zLoc));
	
	ARR_PlayerProjectile* tempProjectile = GetWorld()->SpawnActor<ARR_PlayerProjectile>(WSC[IndexWeaponStruct].PlayerBullet, InitialLocation, InitialiRotation, FActorSpawnParameters());
	
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Passa 3")));
	
	tempProjectile->Var_SpeedProjectile = WSC[IndexWeaponStruct].ProjectileSpeed;
	tempProjectile->Var_Damage = WSC[IndexWeaponStruct].Damage;
	tempProjectile->Var_ScaleAOE = WSC[IndexWeaponStruct].ScaleAOE;
	tempProjectile->Var_TimerDestroyFromBegin = WSC[IndexWeaponStruct].TimerDestroyProjectileFromBegin;
	tempProjectile->Var_DamageAOE = WSC[IndexWeaponStruct].DamageAOE;
	tempProjectile->Var_IsPenetrationProjectile = WSC[IndexWeaponStruct].IsPenetrationBullet;												//Proiettili in weapon - 1 (?)		->Controllare perché 1
}

void URR_Shooting_ActorComponent::Func_TypeShooting(int IndexWeaponStruct, USkeletalMeshComponent* meshPlayer, URR_CameraComponent* CamComp)
{
	if (WSC[IndexWeaponStruct].IsShotgun) {			//Se l'arma è uno shotgun
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Choose shotgun")));
		Func_Shotgun(IndexWeaponStruct, meshPlayer, CamComp);								//Shotgun
	}
	else {											//Altrimenti non è uno shotgun
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Choose normal")));
		Func_Normal(IndexWeaponStruct, CamComp);								//Normal
	}
}

void URR_Shooting_ActorComponent::Func_DecreaseAmmo(int IndexWeaponStruct)
{
	WSC[IndexWeaponStruct].ActualProjectileInBarrage = WSC[IndexWeaponStruct].ActualProjectileInBarrage + WSC[IndexWeaponStruct].AmmoConsumePerShoot;		//Proiettili in barrage - Quelli consumati a colpo
	WSC[IndexWeaponStruct].ActualProjectileInMagazine = WSC[IndexWeaponStruct].ActualProjectileInMagazine - WSC[IndexWeaponStruct].AmmoConsumePerShoot;		//Proiettili in magazine - Quelli consumati a colpo
	WSC[IndexWeaponStruct].ActualProjectileInWeapon = WSC[IndexWeaponStruct].ActualProjectileInWeapon - 1;													//Proiettili in weapon - 1 (?)		->Controllare perché 1
}

void URR_Shooting_ActorComponent::Func_ShootingProjectileV2(int IndexWeaponStruct, USkeletalMeshComponent* meshPlayer, URR_CameraComponent* CamComp)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Shoot 1 %d"), IndexWeaponStruct));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Actual barrage %d"), WSC[IndexWeaponStruct].ActualProjectileInBarrage));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Max barrage %d"), WSC[IndexWeaponStruct].MaxProjectilePerBarrage));

	//while (CanResetBarrage == false) {

	if (WSC[IndexWeaponStruct].ActualProjectileInWeapon > 0 && CanShoot && !InRecharge) {					//Se ci sono proiettili nell'arma e può sparare e non è in ricarica e se ci sono proiettili nel magazine
		CanShoot = false;																																			//Setto a false per far in modo che non possa sparare più																									
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Magazine %d"), WSC[IndexWeaponStruct].ActualProjectileInMagazine));
		if (WSC[IndexWeaponStruct].ActualProjectileInMagazine > 0) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Shoot 2")));
			if (WSC[IndexWeaponStruct].ActualProjectileInBarrage < WSC[IndexWeaponStruct].MaxProjectilePerBarrage) {													//Se i proittili nel barrage sono minori del massimo
				Func_TypeShooting(IndexWeaponStruct, meshPlayer, CamComp);																													//Spawn proiettili tipologia shotgun
				//Func_DecreaseAmmo(IndexWeaponStruct);																													//Spawn proiettili tipologia normal					

				WSC[IndexWeaponStruct].ActualProjectileInBarrage = WSC[IndexWeaponStruct].ActualProjectileInBarrage + WSC[IndexWeaponStruct].AmmoConsumePerShoot;		//Proiettili in barrage - Quelli consumati a colpo
				WSC[IndexWeaponStruct].ActualProjectileInMagazine = WSC[IndexWeaponStruct].ActualProjectileInMagazine - WSC[IndexWeaponStruct].AmmoConsumePerShoot;		//Proiettili in magazine - Quelli consumati a colpo
				WSC[IndexWeaponStruct].ActualProjectileInWeapon = WSC[IndexWeaponStruct].ActualProjectileInWeapon - 1;													//Proiettili in weapon - 1 (?)		->Controllare perché 1

				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Shoot 3")));
				FTimerHandle TimerHandle;																																//Handle per il timer
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]() {}, WSC[IndexWeaponStruct].DelayBetweenSingleShot, false);									//Delay tra i singoli shot
				CanShoot = true;																																				//Setto a true per far in modo che possa sparare

				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Shoot 5")));
			}
			else {																																						//Finito il barrage - Resetta
				CanResetBarrage = true;																																	//Setto a true per resettare il barrage
				CanShoot = true;
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Finito Barrage")));
			}
		}
		else {
			CanShoot = true;
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("false")));
		}
	}
}





void URR_Shooting_ActorComponent::Func_ResetActualProjectileInBarrage(int IndexWeaponStruct)
{
	if (CanResetBarrage) {
		FTimerHandle TimerHandle;																																//Handle per il timer
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]() {}, WSC[IndexWeaponStruct].DelayBetweenBarrage, false);										//Delay tra i singoli shot
		WSC[IndexWeaponStruct].ActualProjectileInBarrage = 0;
		IsLoop = true;
		CanResetBarrage = false;
	}
}

void URR_Shooting_ActorComponent::Func_FirstPartOfShooting(int IndexWeaponStruct, USkeletalMeshComponent* meshPlayer, URR_CameraComponent* CamComp)
{
	if (IsPressedWeaponKey && IsLoop) {
		IsLoop = false;
		if (WSC[IndexWeaponStruct].IsAutomaticWeapon) {
			Func_ShootingProjectileV2(IndexWeaponStruct, meshPlayer, CamComp);
		}
	}
}





void URR_Shooting_ActorComponent::Func_ChooseRecharge(int IndexWeaponStruct, bool InTick, bool InPress)
{
	if (WSC.IsValidIndex(IndexWeaponStruct)) {
		if (InTick) {
			if (WSC[IndexWeaponStruct].ActualProjectileInMagazine <= 0) {
				Func_Recharge(IndexWeaponStruct); //Recharge
			}
		}
		else {
			if (InPress) {
				Func_Recharge(IndexWeaponStruct); //Recharge
			}
		}
	}
}

void URR_Shooting_ActorComponent::Func_Recharge(int IndexWeaponStruct)
{
	if (InRecharge == false) {
		CanShootAnimation = true;
		InRecharge = true;
		UFMODBlueprintStatics::PlayEvent2D(GetWorld(), FModEventRechargeSound, true); //PlayEvent2D Fmod
		UAnimInstance* AnimInstance = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetMesh()->GetAnimInstance();
		const float MontageLength = AnimInstance->Montage_Play(MontageToPlay_Recharge, WSC[IndexWeaponStruct].DelayBetweenMagazine, EMontagePlayReturnType::MontageLength, 0.0f);
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]() {}, WSC[IndexWeaponStruct].DelayBetweenMagazine, false);
		InRecharge = false;
		CanShootAnimation = false;

		if (WSC[IndexWeaponStruct].ActualProjectileInWeapon >= WSC[IndexWeaponStruct].MaxProjectilePerMagazine) {
			WSC[IndexWeaponStruct].ActualProjectileInBarrage = 0;
			WSC[IndexWeaponStruct].ActualProjectileInMagazine = WSC[IndexWeaponStruct].MaxProjectilePerMagazine;

			int tempProjectile = WSC[IndexWeaponStruct].MaxProjectilePerMagazine - WSC[IndexWeaponStruct].ActualProjectileInWeapon;
			WSC[IndexWeaponStruct].RechargeProjectileInWeapon = WSC[IndexWeaponStruct].MaxProjectilePerMagazine - tempProjectile;
		}
		else {
			WSC[IndexWeaponStruct].ActualProjectileInBarrage = 0;
			WSC[IndexWeaponStruct].ActualProjectileInMagazine = WSC[IndexWeaponStruct].ActualProjectileInWeapon;

			int tempProjectile = WSC[IndexWeaponStruct].MaxProjectilePerMagazine - WSC[IndexWeaponStruct].ActualProjectileInWeapon;
			WSC[IndexWeaponStruct].RechargeProjectileInWeapon = WSC[IndexWeaponStruct].MaxProjectilePerMagazine - tempProjectile;
		}
	}
}

//Cose da controllare
//- IsLoop serve?
//- WSC[IndexWeaponStruct].ActualProjectileInWeapon = WSC[IndexWeaponStruct].ActualProjectileInWeapon - 1; in decrease ammo perché -1?
//- IsPressedWeaponKey è meglio metterlo nello shooting component e non nel player
//- CanShootAnimation vedere il findreferences
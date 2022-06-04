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
	

	//for (size_t i = 0; i < WSC.Num(); i++)
	//{
	//	WSC[i].ActualProjectileInMagazine = WSC[i].MaxProjectilePerMagazine;
	//	WSC[i].ActualProjectileInWeapon = WSC[i].MaxProjectileInWeapon;
	//}
}


// Called every frame
void URR_Shooting_ActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URR_Shooting_ActorComponent::Func_Shotgun()
{

}

void URR_Shooting_ActorComponent::Func_Normal()
{

}

void URR_Shooting_ActorComponent::Func_TypeShooting(int IndexWeaponStruct)
{
	if (WSC[IndexWeaponStruct].IsShotgun) {			//Se l'arma è uno shotgun
		Func_Shotgun();								//Shotgun
	}
	else {											//Altrimenti non è uno shotgun
		Func_Normal();								//Normal
	}
}

void URR_Shooting_ActorComponent::Func_DecreaseAmmo(int IndexWeaponStruct)
{
	WSC[IndexWeaponStruct].ActualProjectileInBarrage = WSC[IndexWeaponStruct].ActualProjectileInBarrage - WSC[IndexWeaponStruct].AmmoConsumePerShoot;		//Proiettili in barrage - Quelli consumati a colpo
	WSC[IndexWeaponStruct].ActualProjectileInMagazine = WSC[IndexWeaponStruct].ActualProjectileInMagazine - WSC[IndexWeaponStruct].AmmoConsumePerShoot;		//Proiettili in magazine - Quelli consumati a colpo
	WSC[IndexWeaponStruct].ActualProjectileInWeapon = WSC[IndexWeaponStruct].ActualProjectileInWeapon - 1;													//Proiettili in weapon - 1 (?)		->Controllare perché 1
}

void URR_Shooting_ActorComponent::Func_ShootingProjectileV2(int IndexWeaponStruct)
{
	if (WSC[IndexWeaponStruct].ActualProjectileInWeapon > 0 && CanShoot & !InRecharge && WSC[IndexWeaponStruct].ActualProjectileInMagazine > 0) {					//Se ci sono proiettili nell'arma e può sparare e non è in ricarica e se ci sono proiettili nel magazine
		CanShoot = false;																																			//Setto a false per far in modo che non possa sparare più																									
		if (WSC[IndexWeaponStruct].ActualProjectileInBarrage < WSC[IndexWeaponStruct].MaxProjectilePerBarrage) {													//Se i proittili nel barrage sono minori del massimo
			Func_TypeShooting(IndexWeaponStruct);																													//Spawn proiettili tipologia shotgun
			Func_DecreaseAmmo(IndexWeaponStruct);																													//Spawn proiettili tipologia normal					
		
			FTimerHandle TimerHandle;																																//Handle per il timer
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]() {}, WSC[IndexWeaponStruct].DelayBetweenSingleShot, false);									//Delay tra i singoli shot
		}
		else {																																						//Finito il barrage - Resetta
			CanResetBarrage = true;																																	//Setto a true per resettare il barrage
		}
	}
	CanShoot = true;																																				//Setto a true per far in modo che possa sparare
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

void URR_Shooting_ActorComponent::Func_FirstPartOfShooting(int IndexWeaponStruct)
{
	if (IsPressedWeaponKey && IsLoop) {
		IsLoop = false;
		if (WSC[IndexWeaponStruct].IsAutomaticWeapon) {
			Func_ShootingProjectileV2(IndexWeaponStruct);
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
		}
		else {
			WSC[IndexWeaponStruct].ActualProjectileInBarrage = 0;
			WSC[IndexWeaponStruct].ActualProjectileInMagazine = WSC[IndexWeaponStruct].ActualProjectileInWeapon;
		}
	}
}

//Cose da controllare
//- IsLoop serve?
//- WSC[IndexWeaponStruct].ActualProjectileInWeapon = WSC[IndexWeaponStruct].ActualProjectileInWeapon - 1; in decrease ammo perché -1?
//- IsPressedWeaponKey è meglio metterlo nello shooting component e non nel player
//- CanShootAnimation vedere il findreferences
// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_Ability_ActorComponent.h"
#include "RR_PlayerCharacter.h"

// Sets default values for this component's properties
URR_Ability_ActorComponent::URR_Ability_ActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URR_Ability_ActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URR_Ability_ActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (bAC_CanLaunch_BlackHole) {
		fAC_Temp_CD_BlackHole = fAC_Cooldown_BlackHole;
	}
	else {
		fAC_Temp_CD_BlackHole = fAC_Temp_CD_BlackHole - UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	}

	if (bAC_CanLaunch_Dash) {
		fAC_Temp_CD_Dash = fAC_Cooldown_Dash;
	}
	else {
		fAC_Temp_CD_Dash = fAC_Temp_CD_Dash - UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	}

	if (bAC_CanLaunch_Shield) {
		fAC_Temp_CD_Shield = fAC_Cooldown_Shield;
	}
	else {
		fAC_Temp_CD_Shield = fAC_Temp_CD_Shield - UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	}

	if (bAC_CanLaunch_ShockWave) {
		fAC_Temp_CD_ShockWave = fAC_Cooldown_ShockWave;
	}
	else {
		fAC_Temp_CD_ShockWave = fAC_Temp_CD_ShockWave - UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	}
}

float URR_Ability_ActorComponent::Func_Ability_ShockWave(TSubclassOf<AActor> WaveAreaLarge, TSubclassOf<AActor> WaveAreaSmall)
{
	GetWorld()->SpawnActor<AActor>(WaveAreaLarge, Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetActorLocation(), Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetActorRotation(), FActorSpawnParameters());
	GetWorld()->SpawnActor<AActor>(WaveAreaSmall, Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetActorLocation(), Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetActorRotation(), FActorSpawnParameters());
	return fAC_Cooldown_ShockWave;
}

float URR_Ability_ActorComponent::Func_Ability_BlackHole(FTransform SpawnTransform, TSubclassOf<AActor> BlackHoleProjectile)
{
	GetWorld()->SpawnActor<AActor>(BlackHoleProjectile, SpawnTransform, FActorSpawnParameters());
	return fAC_Cooldown_BlackHole;
}

float URR_Ability_ActorComponent::Func_Ability_Shield(TSubclassOf<AActor> BPShield)
{

	AActor* BPShieldSpawner = GetWorld()->SpawnActor<AActor>(BPShield, Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetMesh()->GetSocketTransform(FName("ShieldPointSpawn")).GetLocation(), Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetMesh()->GetSocketTransform(FName("ShieldPointSpawn")).GetRotation().Rotator(), FActorSpawnParameters());
	BPShieldSpawner->AttachToComponent(Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("ShieldPointSpawn"));
	return fAC_Cooldown_Shield;
}


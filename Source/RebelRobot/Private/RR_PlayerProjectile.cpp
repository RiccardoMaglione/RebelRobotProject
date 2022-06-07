// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_PlayerProjectile.h"

// Sets default values
ARR_PlayerProjectile::ARR_PlayerProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARR_PlayerProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARR_PlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "RebelRobotCharacter.h"

// Sets default values
ARebelRobotCharacter::ARebelRobotCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARebelRobotCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARebelRobotCharacter::RRMoveForward(const float ValoreAvanti)
{
}

void ARebelRobotCharacter::RRMoveRight(const float ValoreDestro)
{
}

// Called every frame
void ARebelRobotCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARebelRobotCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


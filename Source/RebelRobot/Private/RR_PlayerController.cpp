// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_PlayerController.h"

void ARR_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	CurrentMouseCursor = EMouseCursor::Crosshairs;
}
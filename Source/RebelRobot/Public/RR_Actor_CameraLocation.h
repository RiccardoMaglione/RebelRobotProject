// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RR_Actor_CameraLocation.generated.h"

UCLASS()
class REBELROBOT_API ARR_Actor_CameraLocation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARR_Actor_CameraLocation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//UProperty for create root
	USceneComponent* DefaultRootLoc;

	//UProperty for create a reference for camera movement
	UStaticMeshComponent* LocationRef;
};
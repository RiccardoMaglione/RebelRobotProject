// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RebelRobotCharacter.generated.h"

UCLASS()
class REBELROBOT_API ARebelRobotCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARebelRobotCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UFUNCTION(BlueprintCallable, Category = "_RebelRobot | PlayerMovement")
		void RRMoveForward(const float ValoreAvanti);

	UFUNCTION(BlueprintCallable, Category = "_RebelRobot | PlayerMovement")
		void RRMoveRight(const float ValoreDestro);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

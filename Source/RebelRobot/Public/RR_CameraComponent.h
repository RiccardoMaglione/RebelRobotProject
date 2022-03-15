// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "RR_Actor_CameraLocation.h"
#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "RR_CameraComponent.generated.h"

/**
 * 
 */
UCLASS()
class REBELROBOT_API URR_CameraComponent : public UCameraComponent
{
	GENERATED_BODY()
	
public:

	//UProperty for determine lenght of camera step
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Camera")
		float RR_CC_MoveLength = 200;

	//UProperty for set the "CameraLagSpeed" of USpringArmComponent for movement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Camera")
		float RR_CC_Camera_SpringArm_LagSpeed = 5;				

	//UFucntion for calculate direction of camera's movement
	UFUNCTION(BlueprintCallable, Category = "RR | Camera")
		FVector CameraCalculateDirection(ARR_Actor_CameraLocation* ChildCamera, USpringArmComponent* SpringArmComp, float RR_CC_Axis_Forward, float RR_CC_Axis_Right);

	//UFunction for move camera with "Lag" feature of USpringArmComponent
	UFUNCTION(BlueprintCallable, Category = "RR | Camera")
		void CameraMovement(ARR_Actor_CameraLocation* ChildCamera, UCapsuleComponent* CapsuleComponent, USpringArmComponent* SpringArmComp, float RR_CC_Axis_Forward, float RR_CC_Axis_Right);
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "RR_CameraComponent.h"

FVector URR_CameraComponent::CameraCalculateDirection(ARR_Actor_CameraLocation* ChildCamera, USpringArmComponent* SpringArmComp, float RR_CC_Axis_Forward, float RR_CC_Axis_Right)
{
	SpringArmComp->CameraLagSpeed = RR_CC_Camera_SpringArm_LagSpeed;														//Set CameraLagSpeed
	FVector CameraDirForward = ChildCamera->LocationRef->GetForwardVector() * RR_CC_Axis_Forward;							//Calculate forward direction of ChildCamera
	FVector CameraDirRight = ChildCamera->LocationRef->GetRightVector() * RR_CC_Axis_Right;									//Calculate right direction of ChildCamera
	FVector CameraDirSum = CameraDirForward + CameraDirRight;																//Calculate sum between forward and right direction
	return FVector(CameraDirSum * RR_CC_MoveLength);																		//Return multiplier sum with move length
}

void URR_CameraComponent::CameraMovement(ARR_Actor_CameraLocation* ChildCamera, UCapsuleComponent* CapsuleComponent, USpringArmComponent* SpringArmComp, float RR_CC_Axis_Forward, float RR_CC_Axis_Right)
{
	FVector FVDirection = CameraCalculateDirection(ChildCamera, SpringArmComp, RR_CC_Axis_Forward, RR_CC_Axis_Right);		//Call function CameraCalculateDirection
	FVector NewLoc = FVDirection + CapsuleComponent->GetComponentLocation();												//Calculate sum between direction and world location of capsule component
	SpringArmComp->SetWorldLocation(NewLoc);																				//Set world location in NewLoc of SpringArmComp
}

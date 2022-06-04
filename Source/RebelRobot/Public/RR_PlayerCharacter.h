// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RR_CameraComponent.h"
#include "RR_Ability_ActorComponent.h"
#include "RR_UWidget_Menu_Radial.h"
#include "RR_UWidget_Menu_Gameplay.h"
#include "Kismet/GameplayStatics.h"
#include "RR_GameInstance.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RR_PlayerCharacter.generated.h"


UCLASS()
class REBELROBOT_API ARR_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARR_PlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Input")
		bool bInputIsGamepad;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Input")
		int iAbilityIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Widget")
		TSubclassOf<URR_UWidget_Menu_Radial> Class_BP_RadialWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Widget")
		TSubclassOf<URR_UWidget_Menu_Gameplay> Class_BP_GameplayWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Widget")
		URR_UWidget_Menu_Radial* RadialWidgeta;										//Private
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Widget")
		URR_UWidget_Menu_Gameplay* GameplayWidget;									//Private

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Ability")
		URR_Ability_ActorComponent* RR_AbilityComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR ")
		ARR_Actor_CameraLocation* RR_CameraComponent_C;

	UFUNCTION(BlueprintCallable, Category = "RR | Input")
		void AnyKeyDelegate(FKey key);

	UFUNCTION(BlueprintCallable, Category = "RR | Widget")
		void CreateRadialWidget();
	UFUNCTION(BlueprintCallable, Category = "RR | Widget")
		void CreateGameplayWidget();
};

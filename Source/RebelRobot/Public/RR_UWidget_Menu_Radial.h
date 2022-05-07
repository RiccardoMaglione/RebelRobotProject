// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RR_UWidget_Menu_Radial.generated.h"

/**
 * 
 */
UCLASS()
class REBELROBOT_API URR_UWidget_Menu_Radial : public UUserWidget
{
	GENERATED_BODY()
	
	virtual bool Initialize();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		bool bDash_Selected;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		bool bShield_Selected;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		bool bShockWave_Selected;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		bool bBlackHole_Selected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		bool bHover_Dash_Selected;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		bool bHover_Shield_Selected;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		bool bHover_ShockWave_Selected;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		bool bHover_BlackHole_Selected;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_Dash_Selected;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_Shield_Selected;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_BlackHole_Selected;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_ShockWave_Selected;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_NotSelected;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* Button_Dash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* Button_Shield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* Button_BlackHole;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* Button_ShockWave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Image_Dash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Image_Shield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Image_BlackHole;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Image_ShockWave;




	UFUNCTION(BlueprintCallable, Category = "RR | Radial")
		void Radial_HoverDelegate();



	UFUNCTION(BlueprintCallable, Category = "RR | Radial")
		void Radial_DashHover();
	UFUNCTION(BlueprintCallable, Category = "RR | Radial")
		void Radial_ShieldHover();
	UFUNCTION(BlueprintCallable, Category = "RR | Radial")
		void Radial_BlakcHoleHover();
	UFUNCTION(BlueprintCallable, Category = "RR | Radial")
		void Radial_ShockWaveHover();

	UFUNCTION(BlueprintCallable, Category = "RR | Radial")
		void Radial_DashUnhovered();
	UFUNCTION(BlueprintCallable, Category = "RR | Radial")
		void Radial_ShieldUnhovered();
	UFUNCTION(BlueprintCallable, Category = "RR | Radial")
		void Radial_BlackHoleUnhovered();
	UFUNCTION(BlueprintCallable, Category = "RR | Radial")
		void Radial_ShockWaveUnhovered();

};
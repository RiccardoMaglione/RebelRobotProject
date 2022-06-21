// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_Dash_Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_Shield_Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_BlackHole_Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_ShockWave_Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_Dash_Icon_Hover;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_Shield_Icon_Hover;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_BlackHole_Icon_Hover;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_ShockWave_Icon_Hover;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Image_Dash_BordoGiallo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Image_Shield_BordoGiallo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Image_BlackHole_BordoGiallo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Image_ShockWave_BordoGiallo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Image_Dash_Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Image_Shield_Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Image_BlackHole_Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* Image_ShockWave_Icon;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* CanvasPanel_Blackhole;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* CanvasPanel_Circle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TextBlock_Ability;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D ScaleSelected = FVector2D(1.0f, 1.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D ScaleHover = FVector2D(1.0f, 1.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D ScaleUnhover = FVector2D(1.0f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D DashTranslationSelected = FVector2D(0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D BlackHoleTranslationSelected = FVector2D(0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D ShieldTranslationSelected = FVector2D(0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D ShockwaveTranslationSelected = FVector2D(0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D DashTranslationHover = FVector2D(0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D BlackHoleTranslationHover = FVector2D(0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D ShieldTranslationHover = FVector2D(0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D ShockwaveTranslationHover = FVector2D(0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D DashTranslationUnhover = FVector2D(0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D BlackHoleTranslationUnhover = FVector2D(0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D ShieldTranslationUnhover = FVector2D(0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FVector2D ShockwaveTranslationUnhover = FVector2D(0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* CanvasPanel_Dash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* CanvasPanel_Shield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCanvasPanel* CanvasPanel_Shockwave;

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

	UFUNCTION(BlueprintCallable, Category = "RR | Radial")
		void Radial_FuncAbilitySelected();

	UFUNCTION(BlueprintCallable, Category = "RR | Radial")
		void Radial_FuncDashSelected();
	UFUNCTION(BlueprintCallable, Category = "RR | Radial")
		void Radial_FuncShieldSelected();
	UFUNCTION(BlueprintCallable, Category = "RR | Radial")
		void Radial_FuncBlackHoleSelected();
	UFUNCTION(BlueprintCallable, Category = "RR | Radial")
		void Radial_FuncShockWaveSelected();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_Dash_Hover;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_Shield_Hover;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_BlackHole_Hover;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RR | Radial")
		FSlateBrush InBrush_ShockWave_Hover;

};
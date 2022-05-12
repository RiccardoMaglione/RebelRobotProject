// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/WidgetAnimation.h"
#include "RR_UWidget_Menu_Controls.h"
#include "RR_UWidget_Menu_Credits.h"
#include "RR_UWidget_Menu_Option.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RR_UWidget_Menu_Main.generated.h"

/**
 * 
 */
UCLASS()
class REBELROBOT_API URR_UWidget_Menu_Main : public UUserWidget
{
	GENERATED_BODY()
	
	virtual bool Initialize();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* Button_Play;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* Button_Option;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* Button_Credits;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* Button_Controls;
	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Quit_Yes;

	UPROPERTY(meta = (BindWidget))
		class USlider* Slider_Brightness;
	UPROPERTY(meta = (BindWidget))
		class UCheckBox* CheckBox_Fullscreen;

	UFUNCTION()
		void QuitButtonClicked();
	UFUNCTION()
		void BrightnessSliderOnValueChanged(float Value);
	UFUNCTION()
		void FullscreenCheckBoxClicked(bool isChecked);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RM | UI")
		TSubclassOf<URR_UWidget_Menu_Option> OptionWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RM | UI")
		TSubclassOf<URR_UWidget_Menu_Credits> CreditsWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RM | UI")
		TSubclassOf<URR_UWidget_Menu_Controls> ControlsWidget;

	//Da aggiungere per richiamare le animazioni del blueprint da codice
	//UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim), Category = "RM | UI | Animation")
	//	UWidgetAnimation* TestFadeBind;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RR_UWidget_Menu_Option.generated.h"

class URR_UWidget_Menu_Main;

/**
 * 
 */
UCLASS()
class REBELROBOT_API URR_UWidget_Menu_Option : public UUserWidget
{
	GENERATED_BODY()
	
	virtual bool Initialize();

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Back;
	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Exit;

	UPROPERTY(meta = (BindWidget))
		class USlider* Slider_Brightness;

	UFUNCTION()
		void BrightnessSliderOnValueChanged(float Value);
	UFUNCTION()
		void BackExitButtonClicked();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RM | UI")
		TSubclassOf<URR_UWidget_Menu_Main> MainWidget;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_UWidget_Menu_Option.h"
#include "Components/Button.h"
#include "Components/Slider.h"
#include "RR_UWidget_Menu_Main.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/PostProcessVolume.h"

bool URR_UWidget_Menu_Option::Initialize()
{
	Super::Initialize();

	Button_Back->OnClicked.AddDynamic(this, &URR_UWidget_Menu_Option::BackExitButtonClicked);
	Button_Exit->OnClicked.AddDynamic(this, &URR_UWidget_Menu_Option::BackExitButtonClicked);
	Slider_Brightness->OnValueChanged.AddDynamic(this, &URR_UWidget_Menu_Option::BrightnessSliderOnValueChanged);
	return true;
}

void URR_UWidget_Menu_Option::BrightnessSliderOnValueChanged(float Value)
{
	AActor* PPV = UGameplayStatics::GetActorOfClass(GetWorld(), APostProcessVolume::StaticClass());
	if (PPV != nullptr) {
		APostProcessVolume* PPVCasted = Cast<APostProcessVolume>(PPV);
		PPVCasted->Settings.AutoExposureMinBrightness = Value + 0.01;
		PPVCasted->Settings.AutoExposureMaxBrightness = Value - 0.01;
	}
}

void URR_UWidget_Menu_Option::BackExitButtonClicked()
{
	RemoveFromParent();
	if (MainWidget != nullptr) {
		URR_UWidget_Menu_Main* MainWidgetTemp = CreateWidget<URR_UWidget_Menu_Main>(GetWorld(), MainWidget);
		MainWidgetTemp->AddToViewport();
	}
}
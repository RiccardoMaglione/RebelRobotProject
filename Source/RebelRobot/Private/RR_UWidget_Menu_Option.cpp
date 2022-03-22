// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_UWidget_Menu_Option.h"
#include "Components/Button.h"
#include "Components/Slider.h"
#include "RR_UWidget_Menu_Main.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/PostProcessVolume.h"
#include "GameFramework/GameUserSettings.h"
#include "Components/CheckBox.h"

bool URR_UWidget_Menu_Option::Initialize()
{
	Super::Initialize();

	UGameUserSettings* TempGameUserSettings = UGameUserSettings::GetGameUserSettings();
	TempGameUserSettings->LoadSettings();
	if (TempGameUserSettings->GetFullscreenMode() == EWindowMode::Fullscreen) {
		CheckBox_Fullscreen->CheckedState = ECheckBoxState::Checked;
		TempGameUserSettings->SetScreenResolution(TempGameUserSettings->GetDesktopResolution());
		TempGameUserSettings->ApplySettings(false);
		TempGameUserSettings->SaveSettings();
	}
	if (TempGameUserSettings->GetFullscreenMode() == EWindowMode::Windowed || TempGameUserSettings->GetFullscreenMode() == EWindowMode::WindowedFullscreen) {
		CheckBox_Fullscreen->CheckedState = ECheckBoxState::Unchecked;
	}
	
	CheckBox_Fullscreen->OnCheckStateChanged.AddDynamic(this, &URR_UWidget_Menu_Option::FullscreenCheckBoxClicked);


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

void URR_UWidget_Menu_Option::FullscreenCheckBoxClicked(bool isChecked)
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("fullscreen");

	UGameUserSettings* TempGameUserSettings = UGameUserSettings::GetGameUserSettings();
	if (CheckBox_Fullscreen->CheckedState == ECheckBoxState::Checked) {
		TempGameUserSettings->SetFullscreenMode(EWindowMode::Fullscreen);
		TempGameUserSettings->SetScreenResolution(TempGameUserSettings->GetDesktopResolution());
	}
	if (CheckBox_Fullscreen->CheckedState == ECheckBoxState::Unchecked) {
		TempGameUserSettings->SetFullscreenMode(EWindowMode::Windowed);
	}
	TempGameUserSettings->ApplySettings(false);
	TempGameUserSettings->SaveSettings();
}

void URR_UWidget_Menu_Option::BackExitButtonClicked()
{
	RemoveFromParent();
	if (MainWidget != nullptr) {
		URR_UWidget_Menu_Main* MainWidgetTemp = CreateWidget<URR_UWidget_Menu_Main>(GetWorld(), MainWidget);
		MainWidgetTemp->AddToViewport();
	}
}
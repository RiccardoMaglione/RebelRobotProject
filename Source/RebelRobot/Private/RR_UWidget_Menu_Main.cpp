// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_UWidget_Menu_Main.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameUserSettings.h"
#include "Components/Slider.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/PostProcessVolume.h"
#include "Components/CheckBox.h"

bool URR_UWidget_Menu_Main::Initialize()
{
	Super::Initialize();

	UGameUserSettings* TempGameUserSettings = UGameUserSettings::GetGameUserSettings();
	TempGameUserSettings->LoadSettings();
	if (TempGameUserSettings->GetFullscreenMode() == EWindowMode::Fullscreen) {
		TempGameUserSettings->SetFullscreenMode(EWindowMode::Fullscreen);
		TempGameUserSettings->SetScreenResolution(TempGameUserSettings->GetDesktopResolution());
		CheckBox_Fullscreen->CheckedState = ECheckBoxState::Checked;
	}
	if (TempGameUserSettings->GetFullscreenMode() == EWindowMode::Windowed || TempGameUserSettings->GetFullscreenMode() == EWindowMode::WindowedFullscreen) {
		TempGameUserSettings->SetFullscreenMode(EWindowMode::Windowed);
		CheckBox_Fullscreen->CheckedState = ECheckBoxState::Unchecked;
	}
	TempGameUserSettings->ApplySettings(false);
	TempGameUserSettings->SaveSettings();

	CheckBox_Fullscreen->OnCheckStateChanged.AddDynamic(this, &URR_UWidget_Menu_Main::FullscreenCheckBoxClicked);
	Slider_Brightness->OnValueChanged.AddDynamic(this, &URR_UWidget_Menu_Main::BrightnessSliderOnValueChanged);

	Button_Quit_Yes->OnClicked.AddDynamic(this, &URR_UWidget_Menu_Main::QuitButtonClicked);
	return true;
}


void URR_UWidget_Menu_Main::QuitButtonClicked()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}

void URR_UWidget_Menu_Main::BrightnessSliderOnValueChanged(float Value)
{
	AActor* PPV = UGameplayStatics::GetActorOfClass(GetWorld(), APostProcessVolume::StaticClass());
	if (PPV != nullptr) {
		APostProcessVolume* PPVCasted = Cast<APostProcessVolume>(PPV);
		PPVCasted->Settings.AutoExposureMinBrightness = Value + 0.01;
		PPVCasted->Settings.AutoExposureMaxBrightness = Value - 0.01;
	}
}

void URR_UWidget_Menu_Main::FullscreenCheckBoxClicked(bool isChecked)
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

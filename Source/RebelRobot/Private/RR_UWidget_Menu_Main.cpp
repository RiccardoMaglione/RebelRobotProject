// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_UWidget_Menu_Main.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameUserSettings.h"
#include "Components/Slider.h"
#include "Engine/PostProcessVolume.h"
#include "Components/CheckBox.h"

bool URR_UWidget_Menu_Main::Initialize()
{
	Super::Initialize();

	UGameUserSettings* TempGameUserSettings = UGameUserSettings::GetGameUserSettings();                                                                             //Get GameUserSettings                                                                                                                //Save setting in GameUserSettings

	TempGameUserSettings->LoadSettings();                                                                                                                                       //Load setting of GameUserSettings
	if (TempGameUserSettings->GetFullscreenMode() == EWindowMode::Fullscreen) {                                                                                                 //If is fullscreen in GameUseSettings
		CheckBox_Fullscreen->CheckedState = ECheckBoxState::Unchecked;                                                                                                            //Set CheckedState in Checked
		TempGameUserSettings->SetScreenResolution(TempGameUserSettings->GetDesktopResolution());                                                                                //Set resolution of game by desktop resolution
		TempGameUserSettings->ApplySettings(false);                                                                                                                             //Apply setting in GameUserSettings
		TempGameUserSettings->SaveSettings();                                                                                                                                   //Save setting in GameUserSettings
	}
	if (TempGameUserSettings->GetFullscreenMode() == EWindowMode::Windowed || TempGameUserSettings->GetFullscreenMode() == EWindowMode::WindowedFullscreen) {                   //If is Windowed or WindowedFullscreen in GameUseSettings
		CheckBox_Fullscreen->CheckedState = ECheckBoxState::Checked;                                                                                                          //Set CheckedState in Unchecked
	}

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
	if (CheckBox_Fullscreen->CheckedState == ECheckBoxState::Unchecked) {
		TempGameUserSettings->SetFullscreenMode(EWindowMode::Fullscreen);
		TempGameUserSettings->SetScreenResolution(TempGameUserSettings->GetDesktopResolution());
	}
	if (CheckBox_Fullscreen->CheckedState == ECheckBoxState::Checked) {
		TempGameUserSettings->SetFullscreenMode(EWindowMode::Windowed);
	}
	TempGameUserSettings->ApplySettings(false);
	TempGameUserSettings->SaveSettings();
}

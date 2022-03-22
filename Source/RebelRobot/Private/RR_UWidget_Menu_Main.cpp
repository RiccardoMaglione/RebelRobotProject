// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_UWidget_Menu_Main.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameUserSettings.h"

bool URR_UWidget_Menu_Main::Initialize()
{
	Super::Initialize();

	UGameUserSettings* TempGameUserSettings = UGameUserSettings::GetGameUserSettings();
	TempGameUserSettings->LoadSettings();
	if (TempGameUserSettings->GetFullscreenMode() == EWindowMode::Fullscreen) {
		TempGameUserSettings->SetFullscreenMode(EWindowMode::Fullscreen);
		TempGameUserSettings->SetScreenResolution(TempGameUserSettings->GetDesktopResolution());
	}
	if (TempGameUserSettings->GetFullscreenMode() == EWindowMode::Windowed || TempGameUserSettings->GetFullscreenMode() == EWindowMode::WindowedFullscreen) {
		TempGameUserSettings->SetFullscreenMode(EWindowMode::Windowed);
	}
	TempGameUserSettings->ApplySettings(false);
	TempGameUserSettings->SaveSettings();

	Button_Play->OnClicked.AddDynamic(this, &URR_UWidget_Menu_Main::PlayButtonClicked);
	Button_Option->OnClicked.AddDynamic(this, &URR_UWidget_Menu_Main::OptionButtonClicked);
	Button_Credits->OnClicked.AddDynamic(this, &URR_UWidget_Menu_Main::CreditsButtonClicked);
	Button_Controls->OnClicked.AddDynamic(this, &URR_UWidget_Menu_Main::ControlsButtonClicked);
	Button_Quit->OnClicked.AddDynamic(this, &URR_UWidget_Menu_Main::QuitButtonClicked);
	return true;
}

void URR_UWidget_Menu_Main::PlayButtonClicked()
{
	RemoveFromParent();
	UGameplayStatics::OpenLevel(GetWorld(), "AILevel");
}

void URR_UWidget_Menu_Main::OptionButtonClicked()
{
	//RemoveFromParent();
	//if (OptionWidget != nullptr) {
	//	URR_UWidget_Menu_Option* OptionWidgetTemp = CreateWidget<URR_UWidget_Menu_Option>(GetWorld(), OptionWidget);
	//	OptionWidgetTemp->AddToViewport();
	//}
}

void URR_UWidget_Menu_Main::CreditsButtonClicked()
{
	//RemoveFromParent();
	//if (CreditsWidget != nullptr) {
	//	URR_UWidget_Menu_Credits* CreditsWidgetTemp = CreateWidget<URR_UWidget_Menu_Credits>(GetWorld(), CreditsWidget);
	//	CreditsWidgetTemp->AddToViewport();
	//}

	//Play Animation of a variables c++ with reference animation of blueprint
	//UUserWidget::PlayAnimation(TestFadeBind);
}

void URR_UWidget_Menu_Main::ControlsButtonClicked()
{
	//RemoveFromParent();
	//if (ControlsWidget != nullptr) {
	//	URR_UWidget_Menu_Controls* ControlsWidgetTemp = CreateWidget<URR_UWidget_Menu_Controls>(GetWorld(), ControlsWidget);
	//	ControlsWidgetTemp->AddToViewport();
	//}
}

void URR_UWidget_Menu_Main::QuitButtonClicked()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}

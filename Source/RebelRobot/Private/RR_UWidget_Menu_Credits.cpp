// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_UWidget_Menu_Credits.h"
#include "Components/Button.h"
#include "RR_UWidget_Menu_Main.h"
#include "TimerManager.h"

bool URR_UWidget_Menu_Credits::Initialize()
{
    Super::Initialize();

	Button_Back->OnClicked.AddDynamic(this, &URR_UWidget_Menu_Credits::BackExitButtonClicked);
	Button_Exit->OnClicked.AddDynamic(this, &URR_UWidget_Menu_Credits::BackExitButtonClicked);

    return true;
}

void URR_UWidget_Menu_Credits::BackExitButtonClicked()
{
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
		{
			RemoveFromParent();
			if (MainWidget != nullptr) {
				URR_UWidget_Menu_Main* MainWidgetTemp = CreateWidget<URR_UWidget_Menu_Main>(GetWorld(), MainWidget);
				MainWidgetTemp->AddToViewport();
			}
		}, 0.9f, false);
}
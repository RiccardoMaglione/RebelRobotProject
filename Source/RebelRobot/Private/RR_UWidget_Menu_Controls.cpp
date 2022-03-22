// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_UWidget_Menu_Controls.h"
#include "Components/Button.h"
#include "RR_UWidget_Menu_Main.h"

bool URR_UWidget_Menu_Controls::Initialize()
{
	Super::Initialize();

	Button_Back->OnClicked.AddDynamic(this, &URR_UWidget_Menu_Controls::BackExitButtonClicked);
	Button_Exit->OnClicked.AddDynamic(this, &URR_UWidget_Menu_Controls::BackExitButtonClicked);

	return true;
}

void URR_UWidget_Menu_Controls::BackExitButtonClicked()
{
	RemoveFromParent();
	if (MainWidget != nullptr) {
		URR_UWidget_Menu_Main* MainWidgetTemp = CreateWidget<URR_UWidget_Menu_Main>(GetWorld(), MainWidget);
		MainWidgetTemp->AddToViewport();
	}
}

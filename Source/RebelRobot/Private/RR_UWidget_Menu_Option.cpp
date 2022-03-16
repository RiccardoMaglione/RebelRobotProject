// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_UWidget_Menu_Option.h"
#include "Components/Button.h"
#include "RR_UWidget_Menu_Main.h"

bool URR_UWidget_Menu_Option::Initialize()
{
	Super::Initialize();

	Button_Back->OnClicked.AddDynamic(this, &URR_UWidget_Menu_Option::BackExitButtonClicked);
	Button_Exit->OnClicked.AddDynamic(this, &URR_UWidget_Menu_Option::BackExitButtonClicked);

	return true;
}

void URR_UWidget_Menu_Option::BackExitButtonClicked()
{
	RemoveFromParent();
	if (MainWidget != nullptr) {
		URR_UWidget_Menu_Main* MainWidgetTemp = CreateWidget<URR_UWidget_Menu_Main>(GetWorld(), MainWidget);
		MainWidgetTemp->AddToViewport();
	}
}
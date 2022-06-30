// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RR_UWidget_Menu_Pause.generated.h"

/**
 * 
 */
UCLASS()
class REBELROBOT_API URR_UWidget_Menu_Pause : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();

public:
	UPROPERTY(meta = (BindWidget))
		class UCheckBox* CheckBox_Fullscreen;

	UFUNCTION()
		void FullscreenCheckBoxClickedPause(bool isChecked);
};

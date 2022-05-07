// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_UWidget_Menu_Radial.h"
#include "..\Public\RR_UWidget_Menu_Radial.h"
#include "Components/Button.h"
#include "Components/Image.h"

bool URR_UWidget_Menu_Radial::Initialize()
{
    Super::Initialize();

    Button_Dash->OnUnhovered.AddDynamic(this, &URR_UWidget_Menu_Radial::Radial_DashUnhovered);
    Button_Shield->OnUnhovered.AddDynamic(this, &URR_UWidget_Menu_Radial::Radial_ShieldUnhovered);
    Button_BlackHole->OnUnhovered.AddDynamic(this, &URR_UWidget_Menu_Radial::Radial_BlackHoleUnhovered);
    Button_ShockWave->OnUnhovered.AddDynamic(this, &URR_UWidget_Menu_Radial::Radial_ShockWaveUnhovered);

    return true;
}

void URR_UWidget_Menu_Radial::Radial_HoverDelegate()
{
    //SetBrush
    //AllbAbilitySelected1 = false
    //ThisbAbilitySelected = true
    //Get player character and cast to v4
    //Get Ability component
    //Get ACCooldown
    //Append String and convert to text
    //Set text <- TextBlockAbility
}

#pragma region
void URR_UWidget_Menu_Radial::Radial_DashHover()
{
    Image_Dash->SetBrush(InBrush_Dash_Selected);
    bHover_BlackHole_Selected = false;
    bHover_Shield_Selected = false;
    bHover_ShockWave_Selected = false;
    bHover_Dash_Selected = true;
}

void URR_UWidget_Menu_Radial::Radial_ShieldHover()
{
    Image_Shield->SetBrush(InBrush_Shield_Selected);
    bHover_Dash_Selected = false;
    bHover_BlackHole_Selected = false;
    bHover_ShockWave_Selected = false;
    bHover_Shield_Selected = true;
}

void URR_UWidget_Menu_Radial::Radial_BlakcHoleHover()
{
    Image_BlackHole->SetBrush(InBrush_BlackHole_Selected);
    bHover_Dash_Selected = false;
    bHover_Shield_Selected = false;
    bHover_ShockWave_Selected = false;
    bHover_BlackHole_Selected = true;
}

void URR_UWidget_Menu_Radial::Radial_ShockWaveHover()
{
    Image_ShockWave->SetBrush(InBrush_ShockWave_Selected);
    bHover_Dash_Selected = false;
    bHover_Shield_Selected = false;
    bHover_BlackHole_Selected = false;
    bHover_ShockWave_Selected = true;
}
#pragma endregion Radial Hover Delegate

#pragma region
void URR_UWidget_Menu_Radial::Radial_DashUnhovered()
{
    if (!bDash_Selected) {
        Image_Dash->UImage::SetBrush(InBrush_NotSelected);
        bHover_Dash_Selected = false;
    }
}

void URR_UWidget_Menu_Radial::Radial_ShieldUnhovered()
{
    if (!bShield_Selected) {
        Image_Shield->UImage::SetBrush(InBrush_NotSelected);
        bHover_Shield_Selected = false;
    }
}

void URR_UWidget_Menu_Radial::Radial_BlackHoleUnhovered()
{
    if (!bBlackHole_Selected) {
        Image_BlackHole->UImage::SetBrush(InBrush_NotSelected);
        bHover_BlackHole_Selected = false;
    }
}

void URR_UWidget_Menu_Radial::Radial_ShockWaveUnhovered()
{
    if (!bShockWave_Selected) {
        Image_ShockWave->UImage::SetBrush(InBrush_NotSelected);
        bHover_ShockWave_Selected = false;
    }
}
#pragma endregion Radial Unhovered Delegate
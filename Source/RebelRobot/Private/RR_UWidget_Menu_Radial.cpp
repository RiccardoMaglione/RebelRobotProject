// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_UWidget_Menu_Radial.h"
#include "..\Public\RR_UWidget_Menu_Radial.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/CanvasPanel.h"
#include "RR_PlayerCharacter.h"

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
    if (Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->iAbilityIndex != 2) {
        Image_Dash->SetBrush(InBrush_Dash_Hover);
        Image_Dash->UImage::SetRenderScale(ScaleHover);
        Image_Dash_Icon->SetBrush(InBrush_Dash_Icon_Hover);
        Image_Dash_Icon->UImage::SetRenderScale(ScaleHover);
        bHover_BlackHole_Selected = false;
        bHover_Shield_Selected = false;
        bHover_ShockWave_Selected = false;
        bHover_Dash_Selected = true;
        Image_Dash_BordoGiallo->UImage::SetRenderScale(ScaleHover);

        CanvasPanel_Dash->UCanvasPanel::SetRenderTranslation(DashTranslationHover);
    }
}

void URR_UWidget_Menu_Radial::Radial_ShieldHover()
{
    if (Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->iAbilityIndex != 0) {
        Image_Shield->SetBrush(InBrush_Shield_Hover);
        Image_Shield->UImage::SetRenderScale(ScaleHover);
        Image_Shield_Icon->SetBrush(InBrush_Shield_Icon_Hover);
        Image_Shield_Icon->UImage::SetRenderScale(ScaleHover);
        bHover_Dash_Selected = false;
        bHover_BlackHole_Selected = false;
        bHover_ShockWave_Selected = false;
        bHover_Shield_Selected = true;
        Image_Shield_BordoGiallo->UImage::SetRenderScale(ScaleHover);

        CanvasPanel_Shield->UCanvasPanel::SetRenderTranslation(ShieldTranslationHover);
    }
}

void URR_UWidget_Menu_Radial::Radial_BlakcHoleHover()
{
    if (Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->iAbilityIndex != 1) {
        Image_BlackHole->SetBrush(InBrush_BlackHole_Hover);
        Image_BlackHole->UImage::SetRenderScale(ScaleHover);
        Image_BlackHole_Icon->SetBrush(InBrush_BlackHole_Icon_Hover);
        Image_BlackHole_Icon->UImage::SetRenderScale(ScaleHover);
        CanvasPanel_Blackhole->UCanvasPanel::SetRenderScale(ScaleHover);
        bHover_Dash_Selected = false;
        bHover_Shield_Selected = false;
        bHover_ShockWave_Selected = false;
        bHover_BlackHole_Selected = true;
        Image_BlackHole_BordoGiallo->UImage::SetRenderScale(ScaleHover);

        CanvasPanel_Blackhole->UCanvasPanel::SetRenderTranslation(BlackHoleTranslationHover);
    }
}

void URR_UWidget_Menu_Radial::Radial_ShockWaveHover()
{
    if (Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->iAbilityIndex != 3) {
        Image_ShockWave->SetBrush(InBrush_ShockWave_Hover);
        Image_ShockWave->UImage::SetRenderScale(ScaleHover);
        Image_ShockWave_Icon->SetBrush(InBrush_ShockWave_Icon_Hover);
        Image_ShockWave_Icon->UImage::SetRenderScale(ScaleHover);
        bHover_Dash_Selected = false;
        bHover_Shield_Selected = false;
        bHover_BlackHole_Selected = false;
        bHover_ShockWave_Selected = true;
        Image_ShockWave_BordoGiallo->UImage::SetRenderScale(ScaleHover);

        CanvasPanel_Shockwave->UCanvasPanel::SetRenderTranslation(ShockwaveTranslationHover);
    }
}
#pragma endregion Radial Hover Delegate

#pragma region
void URR_UWidget_Menu_Radial::Radial_DashUnhovered()
{
    if (!bDash_Selected) {
        Image_Dash->UImage::SetBrush(InBrush_NotSelected);
        Image_Dash->UImage::SetRenderScale(ScaleUnhover);
        Image_Dash_Icon->UImage::SetBrush(InBrush_Dash_Icon);
        Image_Dash_Icon->UImage::SetRenderScale(ScaleUnhover);
        bHover_Dash_Selected = false;

        CanvasPanel_Dash->UCanvasPanel::SetRenderTranslation(DashTranslationUnhover);
    }
}        

void URR_UWidget_Menu_Radial::Radial_ShieldUnhovered()
{
    if (!bShield_Selected) {
        Image_Shield->UImage::SetBrush(InBrush_NotSelected);
        Image_Shield->UImage::SetRenderScale(ScaleUnhover);
        Image_Shield_Icon->UImage::SetBrush(InBrush_Shield_Icon);
        Image_Shield_Icon->UImage::SetRenderScale(ScaleUnhover);
        bHover_Shield_Selected = false;

        CanvasPanel_Shield->UCanvasPanel::SetRenderTranslation(ShieldTranslationUnhover);
    }
}

void URR_UWidget_Menu_Radial::Radial_BlackHoleUnhovered()
{
    if (!bBlackHole_Selected) {
        Image_BlackHole->UImage::SetBrush(InBrush_NotSelected);
        Image_BlackHole->UImage::SetRenderScale(ScaleUnhover);
        Image_BlackHole_Icon->UImage::SetBrush(InBrush_BlackHole_Icon);
        Image_BlackHole_Icon->UImage::SetRenderScale(ScaleUnhover);
        CanvasPanel_Blackhole->UCanvasPanel::SetRenderScale(ScaleUnhover);
        bHover_BlackHole_Selected = false;

        CanvasPanel_Blackhole->UCanvasPanel::SetRenderTranslation(BlackHoleTranslationUnhover);
    }
}

void URR_UWidget_Menu_Radial::Radial_ShockWaveUnhovered()
{
    if (!bShockWave_Selected) {
        Image_ShockWave->UImage::SetBrush(InBrush_NotSelected);
        Image_ShockWave->UImage::SetRenderScale(ScaleUnhover);
        Image_ShockWave_Icon->UImage::SetBrush(InBrush_ShockWave_Icon);
        Image_ShockWave_Icon->UImage::SetRenderScale(ScaleUnhover);
        bHover_ShockWave_Selected = false;

        CanvasPanel_Shockwave->UCanvasPanel::SetRenderTranslation(ShockwaveTranslationUnhover);
    }
}
#pragma endregion Radial Unhovered Delegate

void URR_UWidget_Menu_Radial::Radial_FuncAbilitySelected()
{
    /*
    SetBrush Image dash e InBrushDashSelected
    SetRenderScale image dash scale 1 1
    SetRenderTranslation image dash 0 0
    cast get player character to v4rrcharacter
    get ability component
    get ac cooldown das
    append
    set text text textblockability to string append
    SetRenderScale image shield image shock wave canvas panel blackhole
    setrendertranslation image shield image shock wave canvas panel blackhole
    dashselected = true
    shieldselected = false
    blackholeselected = false
    shockwaveselected = false
    Set brush image shock wave image black hole image shield in brush not selected
    Canvas panel circle set render transform angle 0
    cast to player character to v4
    ability index = 2
    Set visible image dash bordo giallo
    set hidden visible image shield bordo giallo black hole bg showckwave bg
    */


    //ImageDash
    //InBrushDashSelected
}

void URR_UWidget_Menu_Radial::Radial_FuncDashSelected()
{
    Image_Dash->UImage::SetBrush(InBrush_Dash_Selected);
    Image_Dash->UImage::SetRenderScale(ScaleSelected);
    Image_Dash->UImage::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    
    CanvasPanel_Dash->UCanvasPanel::SetRenderTranslation(DashTranslationSelected);

    Image_Dash_Icon->SetBrush(InBrush_Dash_Icon_Hover);
    Image_Dash_Icon->UImage::SetRenderScale(ScaleSelected);
    FString base = "Dash\nEFFECT: Lorem Ipsum\nCOOLDOWN: ";
    //FString sCooldownValue = FString::SanitizeFloat(Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->RR_AbilityComponent->fAC_Cooldown_Dash);
    FString sCooldownValue = FString::SanitizeFloat(2.0f);
    FString baseFinal = " Seconds\nSTATUS: AVALAIBLE";
    base.Append(sCooldownValue);
    base.Append(baseFinal);
    TextBlock_Ability->SetText(FText::FromString(base));

    Image_Shield->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_ShockWave->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    CanvasPanel_Blackhole->UCanvasPanel::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_Shield->UImage::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    Image_ShockWave->UImage::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    CanvasPanel_Blackhole->UCanvasPanel::SetRenderTranslation(FVector2D(0.0f, 0.0f));

    CanvasPanel_Shield->UCanvasPanel::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    CanvasPanel_Shockwave->UCanvasPanel::SetRenderTranslation(FVector2D(0.0f, 0.0f));

    Image_Shield_Icon->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_ShockWave_Icon->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_BlackHole_Icon->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));

    bDash_Selected = true;
    bShield_Selected = false;
    bBlackHole_Selected = false;
    bShockWave_Selected = false;

    Image_ShockWave->UImage::SetBrush(InBrush_NotSelected);
    Image_BlackHole->UImage::SetBrush(InBrush_NotSelected);
    Image_Shield->UImage::SetBrush(InBrush_NotSelected);

    Image_Shield_Icon->UImage::SetBrush(InBrush_Shield_Icon);
    Image_BlackHole_Icon->UImage::SetBrush(InBrush_BlackHole_Icon);
    Image_ShockWave_Icon->UImage::SetBrush(InBrush_ShockWave_Icon);

    CanvasPanel_Circle->UCanvasPanel::SetRenderTransformAngle(0.0f);

    Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->iAbilityIndex = 2;

    Image_Dash_BordoGiallo->SetVisibility(ESlateVisibility::Visible);
    Image_Dash_BordoGiallo->UImage::SetRenderScale(ScaleSelected);

    Image_Shield_BordoGiallo->SetVisibility(ESlateVisibility::Hidden);
    Image_BlackHole_BordoGiallo->SetVisibility(ESlateVisibility::Hidden);
    Image_ShockWave_BordoGiallo->SetVisibility(ESlateVisibility::Hidden);


}

void URR_UWidget_Menu_Radial::Radial_FuncShieldSelected()
{
    Image_Shield->UImage::SetBrush(InBrush_Shield_Selected);
    Image_Shield->UImage::SetRenderScale(ScaleSelected);
    Image_Shield->UImage::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    
    CanvasPanel_Shield->UCanvasPanel::SetRenderTranslation(ShieldTranslationSelected);

    Image_Shield_Icon->SetBrush(InBrush_Shield_Icon_Hover);
    Image_Shield_Icon->UImage::SetRenderScale(ScaleSelected);
    FString base = "Shield\nEFFECT: Lorem Ipsum\nCOOLDOWN: ";
    //FString sCooldownValue = FString::SanitizeFloat(Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->RR_AbilityComponent->fAC_Cooldown_Shield);
    FString sCooldownValue = FString::SanitizeFloat(5.0f);
    FString baseFinal = " Seconds\nSTATUS: AVALAIBLE";
    base.Append(sCooldownValue);
    base.Append(baseFinal);
    TextBlock_Ability->SetText(FText::FromString(base));
    
    Image_Dash->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_ShockWave->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    CanvasPanel_Blackhole->UCanvasPanel::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_Dash->UImage::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    Image_ShockWave->UImage::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    CanvasPanel_Blackhole->UCanvasPanel::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    
    CanvasPanel_Dash->UCanvasPanel::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    CanvasPanel_Shockwave->UCanvasPanel::SetRenderTranslation(FVector2D(0.0f, 0.0f));

    Image_Dash_Icon->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_ShockWave_Icon->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_BlackHole_Icon->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));

    bDash_Selected = false;
    bShield_Selected = true;
    bBlackHole_Selected = false;
    bShockWave_Selected = false;
    
    Image_ShockWave->UImage::SetBrush(InBrush_NotSelected);
    Image_BlackHole->UImage::SetBrush(InBrush_NotSelected);
    Image_Dash->UImage::SetBrush(InBrush_NotSelected);

    Image_Dash_Icon->UImage::SetBrush(InBrush_Dash_Icon);
    Image_BlackHole_Icon->UImage::SetBrush(InBrush_BlackHole_Icon);
    Image_ShockWave_Icon->UImage::SetBrush(InBrush_ShockWave_Icon);
    
    CanvasPanel_Circle->UCanvasPanel::SetRenderTransformAngle(90.0f);
    
    Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->iAbilityIndex = 0;
    
    Image_Shield_BordoGiallo->SetVisibility(ESlateVisibility::Visible);
    Image_Shield_BordoGiallo->UImage::SetRenderScale(ScaleSelected);

    Image_Dash_BordoGiallo->SetVisibility(ESlateVisibility::Hidden);
    Image_BlackHole_BordoGiallo->SetVisibility(ESlateVisibility::Hidden);
    Image_ShockWave_BordoGiallo->SetVisibility(ESlateVisibility::Hidden);
}

void URR_UWidget_Menu_Radial::Radial_FuncBlackHoleSelected()
{
    Image_BlackHole->UImage::SetBrush(InBrush_BlackHole_Selected);
    CanvasPanel_Blackhole->UCanvasPanel::SetRenderScale(ScaleSelected);
    CanvasPanel_Blackhole->UCanvasPanel::SetRenderTranslation(BlackHoleTranslationSelected);

    Image_BlackHole_Icon->UImage::SetBrush(InBrush_BlackHole_Icon_Hover);
    Image_BlackHole_Icon->UImage::SetRenderScale(ScaleSelected);
    FString base = "BlackHole\nEFFECT: Lorem Ipsum\nCOOLDOWN: ";
    //FString sCooldownValue = FString::SanitizeFloat(Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->RR_AbilityComponent->fAC_Cooldown_BlackHole);
    FString sCooldownValue = FString::SanitizeFloat(15.0f);
    FString baseFinal = " Seconds\nSTATUS: AVALAIBLE";
    base.Append(sCooldownValue);
    base.Append(baseFinal);
    TextBlock_Ability->SetText(FText::FromString(base));
    
    Image_Shield->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_Dash->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_ShockWave->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_Shield->UImage::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    Image_Dash->UImage::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    Image_ShockWave->UImage::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    
    CanvasPanel_Shield->UCanvasPanel::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    CanvasPanel_Shockwave->UCanvasPanel::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    CanvasPanel_Dash->UCanvasPanel::SetRenderTranslation(FVector2D(0.0f, 0.0f));

    Image_Shield_Icon->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_ShockWave_Icon->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_Dash_Icon->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));

    bDash_Selected = false;
    bShield_Selected = false;
    bBlackHole_Selected = true;
    bShockWave_Selected = false;
    
    Image_ShockWave->UImage::SetBrush(InBrush_NotSelected);
    Image_Shield->UImage::SetBrush(InBrush_NotSelected);
    Image_Dash->UImage::SetBrush(InBrush_NotSelected);
    
    Image_Dash_Icon->UImage::SetBrush(InBrush_Dash_Icon);
    Image_Shield_Icon->UImage::SetBrush(InBrush_Shield_Icon);
    Image_ShockWave_Icon->UImage::SetBrush(InBrush_ShockWave_Icon);

    CanvasPanel_Circle->UCanvasPanel::SetRenderTransformAngle(-90.0f);
    
    Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->iAbilityIndex = 1;
    
    Image_BlackHole_BordoGiallo->SetVisibility(ESlateVisibility::Visible);
    Image_BlackHole_BordoGiallo->UImage::SetRenderScale(ScaleSelected);

    Image_Shield_BordoGiallo->SetVisibility(ESlateVisibility::Hidden);
    Image_Dash_BordoGiallo->SetVisibility(ESlateVisibility::Hidden);
    Image_ShockWave_BordoGiallo->SetVisibility(ESlateVisibility::Hidden);
}

void URR_UWidget_Menu_Radial::Radial_FuncShockWaveSelected()
{
    Image_ShockWave->UImage::SetBrush(InBrush_ShockWave_Selected);
    Image_ShockWave->UImage::SetRenderScale(ScaleSelected);
    Image_ShockWave->UImage::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    
    CanvasPanel_Shockwave->UCanvasPanel::SetRenderTranslation(ShockwaveTranslationSelected);

    CanvasPanel_Shockwave->UCanvasPanel::SetRenderTranslation(FVector2D(0.0f, 0.0f));

    Image_ShockWave_Icon->UImage::SetBrush(InBrush_ShockWave_Icon_Hover);
    Image_ShockWave_Icon->UImage::SetRenderScale(ScaleSelected);
    FString base = "ShockWave\nEFFECT: Lorem Ipsum\nCOOLDOWN: ";
    //FString sCooldownValue = FString::SanitizeFloat(Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->RR_AbilityComponent->fAC_Cooldown_ShockWave);
    FString sCooldownValue = FString::SanitizeFloat(4.0f);
    FString baseFinal = " Seconds\nSTATUS: AVALAIBLE";
    base.Append(sCooldownValue);
    base.Append(baseFinal);
    TextBlock_Ability->SetText(FText::FromString(base));
    
    Image_Shield->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_Dash->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    CanvasPanel_Blackhole->UCanvasPanel::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_Shield->UImage::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    Image_Dash->UImage::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    CanvasPanel_Blackhole->UCanvasPanel::SetRenderTranslation(FVector2D(0.0f, 0.0f));

    CanvasPanel_Shield->UCanvasPanel::SetRenderTranslation(FVector2D(0.0f, 0.0f));
    CanvasPanel_Dash->UCanvasPanel::SetRenderTranslation(FVector2D(0.0f, 0.0f));

    Image_Shield_Icon->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_BlackHole_Icon->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));
    Image_Dash_Icon->UImage::SetRenderScale(FVector2D(1.0f, 1.0f));

    bDash_Selected = false;
    bShield_Selected = false;
    bBlackHole_Selected = false;
    bShockWave_Selected = true;
    
    Image_Dash->UImage::SetBrush(InBrush_NotSelected);
    Image_BlackHole->UImage::SetBrush(InBrush_NotSelected);
    Image_Shield->UImage::SetBrush(InBrush_NotSelected);
    
    Image_Dash_Icon->UImage::SetBrush(InBrush_Dash_Icon);
    Image_Shield_Icon->UImage::SetBrush(InBrush_Shield_Icon);
    Image_BlackHole_Icon->UImage::SetBrush(InBrush_BlackHole_Icon);

    CanvasPanel_Circle->UCanvasPanel::SetRenderTransformAngle(180.0f);
    
    Cast<ARR_PlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->iAbilityIndex = 3;
    
    Image_ShockWave_BordoGiallo->SetVisibility(ESlateVisibility::Visible);
    Image_ShockWave_BordoGiallo->UImage::SetRenderScale(ScaleSelected);

    Image_Shield_BordoGiallo->SetVisibility(ESlateVisibility::Hidden);
    Image_BlackHole_BordoGiallo->SetVisibility(ESlateVisibility::Hidden);
    Image_Dash_BordoGiallo->SetVisibility(ESlateVisibility::Hidden);
}

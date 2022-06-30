// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_PlayerCharacter.h"

// Sets default values
ARR_PlayerCharacter::ARR_PlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARR_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	Cast<URR_GameInstance>(GetGameInstance())->LevelOfReturn = UGameplayStatics::GetCurrentLevelName(GetWorld());
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Black, Cast<URR_GameInstance>(GetGameInstance())->LevelOfReturn);

	CreateRadialWidget();
	CreateGameplayWidget();
}

// Called every frame
void ARR_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARR_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	InputComponent->BindAction("Key_AnyKey_Delegate", IE_Pressed, this, &ARR_PlayerCharacter::AnyKeyDelegate);
}

void ARR_PlayerCharacter::AnyKeyDelegate(FKey key)
{
	if (key.IsGamepadKey()) {
		bInputIsGamepad = true;
		//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Black, FString::Printf(TEXT("Bool: %s"), bInputIsGamepad ? TEXT("true") : TEXT("false")));
	}
	else if (!key.IsGamepadKey() || key.IsMouseButton()) {			//key.IsKeyboardKey() al posto di !key.IsGamepadKey()
		bInputIsGamepad = false;
		//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Black, FString::Printf(TEXT("Bool: %s"), bInputIsGamepad ? TEXT("true") : TEXT("false")));
	}
}

void ARR_PlayerCharacter::CreateRadialWidget()
{
	RadialWidgeta = CreateWidget<URR_UWidget_Menu_Radial>(GetWorld(), Class_BP_RadialWidget);
}

void ARR_PlayerCharacter::CreateGameplayWidget()
{
	GameplayWidget = CreateWidget<URR_UWidget_Menu_Gameplay>(GetWorld(), Class_BP_GameplayWidget);
	GameplayWidget->AddToViewport();

	for (size_t i = 0; i < LevelNameHiddenWidget.Num(); i++)
	{
		if (LevelNameHiddenWidget[i] == UGameplayStatics::GetCurrentLevelName(GetWorld())){
			GameplayWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

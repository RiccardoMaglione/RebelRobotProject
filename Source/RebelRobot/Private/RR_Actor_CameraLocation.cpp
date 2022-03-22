// Fill out your copyright notice in the Description page of Project Settings.


#include "RR_Actor_CameraLocation.h"

// Sets default values
ARR_Actor_CameraLocation::ARR_Actor_CameraLocation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRootLoc = CreateDefaultSubobject<USceneComponent>("DefaultRoot");										//Set custom root of actor
	LocationRef = CreateDefaultSubobject<UStaticMeshComponent>("LocRef");											//Set object for reference of type UStaticMeshComponent
	DefaultRootLoc->SetupAttachment(RootComponent);																	//Set parent of DefaultRootLoc to RootComponent
	LocationRef->SetupAttachment(DefaultRootLoc);																	//Set parent of LocationRef to DefaultRootLoc
}

// Called when the game starts or when spawned
void ARR_Actor_CameraLocation::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARR_Actor_CameraLocation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetWorld() != nullptr && GetWorld()->GetFirstPlayerController() != nullptr && GetWorld()->GetFirstPlayerController()->GetPawn() != nullptr) {
		LocationRef->SetWorldLocation(GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());			//Set world location of LocationRef to Player location
	}
}
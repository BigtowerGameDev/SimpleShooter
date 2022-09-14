// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

// Called when the game starts or when spawned
void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

    HUDScreen = CreateWidget(this, HUDClass);
    if(HUDScreen != nullptr)
    {
        HUDScreen->AddToViewport();
    }
	
}
void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);
    if(HUDScreen != nullptr)
    {
        HUDScreen->RemoveFromViewport();
    }
    if(bIsWinner)
    {
        UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
        if(WinScreen != nullptr)
        {
            WinScreen->AddToViewport();
        }
    }else
    {
        UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
        if(LoseScreen != nullptr)
        {
            LoseScreen->AddToViewport();
        }
    }
    

    //UE_LOG(LogTemp, Display, TEXT("We had finish!"));
    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
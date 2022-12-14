// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

// Called when the game starts or when spawned
void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();
    PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    //SetFocus(PlayerPawn);
    
    if(AIBehavior != nullptr){
        RunBehaviorTree(AIBehavior);  
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"),GetPawn()->GetActorLocation());
    }
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);  
    /* 
    if(LineOfSightTo(PlayerPawn))
    {
        //Setting PlayerLocation & LastKnownPlayerLocation
        GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"),PlayerPawn->GetActorLocation());
        GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"),PlayerPawn->GetActorLocation());
    }else{
        //Clear PlayerLocation
        GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
    }
    */
}

bool AShooterAIController::IsDead() const
{
    AShooterCharacter* ControllerCharacter = Cast<AShooterCharacter>(GetPawn());

    if(ControllerCharacter != nullptr)
    {
        return ControllerCharacter->IsDead();
    }
    
    return true;
}
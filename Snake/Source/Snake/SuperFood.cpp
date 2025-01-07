// Fill out your copyright notice in the Description page of Project Settings.


#include "SuperFood.h"
#include "Components/BoxComponent.h"

ASuperFood::ASuperFood()
{
	duration = 25;

	score = 30;
}

void ASuperFood::BeginPlay()
{	
	Super::BeginPlay();
}

void ASuperFood::Spawn()
{
	float Time = FMath::FRandRange(15.0f, 50.0f);

	FTimerHandle TimerHandle;

	FTimerDelegate TimerCallback;
	TimerCallback.BindLambda([this]()
	{
		FVector SpawnLocation = FMath::RandPointInBox(FBox(FVector(-331, -497, 315), FVector(2293, 2700, 315)));

		if (this)
		{
			ASuperFood* Food = GetWorld()->SpawnActor<ASuperFood>(this->GetClass(), SpawnLocation, FRotator());
		}
	});

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerCallback, Time, false);
}
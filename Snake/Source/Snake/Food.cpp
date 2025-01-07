// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "Components/BoxComponent.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Food = CreateDefaultSubobject<UStaticMeshComponent>("Food");
	SetRootComponent(Food);

	Collision = CreateDefaultSubobject<UBoxComponent>("Collision");
	Collision->SetupAttachment(Food);

	score = 10;
}

void AFood::Spawn()
{
	FVector SpawnLocation = FMath::RandPointInBox(FBox(FVector(-331, -497, 315), FVector(2293, 2700, 315)));

	AFood* food = GetWorld()->SpawnActor<AFood>(this->GetClass(), SpawnLocation, FRotator::ZeroRotator);
}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AFood::GetScore()
{
	return score;
}


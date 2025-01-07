// Fill out your copyright notice in the Description page of Project Settings.


#include "OnePeaceOfBoard.h"
#include "Components/PointLightComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AOnePeaceOfBoard::AOnePeaceOfBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Light = CreateDefaultSubobject<UPointLightComponent>("Light");

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh"); 
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AOnePeaceOfBoard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOnePeaceOfBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


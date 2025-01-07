// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeSpline.h"
#include "Components/SplineMeshComponent.h"

// Sets default values
ASnakeSpline::ASnakeSpline()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SnakeSpline = CreateDefaultSubobject<USplineMeshComponent>("SnakeSpline");
}

// Called when the game starts or when spawned
void ASnakeSpline::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASnakeSpline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


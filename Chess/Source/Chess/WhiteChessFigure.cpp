// Fill out your copyright notice in the Description page of Project Settings.


#include "WhiteChessFigure.h"

void AWhiteChessFigure::AttackKing()
{

}

// Sets default values
AWhiteChessFigure::AWhiteChessFigure()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWhiteChessFigure::BeginPlay()
{
	Super::BeginPlay();
	
}

bool AWhiteChessFigure::LineTrace(FVector Direction)
{
	return false;
}

void AWhiteChessFigure::ShowLocations()
{

}

void AWhiteChessFigure::TurnOffLocations()
{

}

void AWhiteChessFigure::MoveUnderAttack()
{

}

// Called every frame
void AWhiteChessFigure::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWhiteChessFigure::move(FVector Direction)
{

}

UStaticMeshComponent* AWhiteChessFigure::GetMesh()
{
	return Mesh;
}

bool AWhiteChessFigure::CanAttack(FVector Direction)
{
	return false;
}

void AWhiteChessFigure::Attack(ABlackChessFigure* BlackFigure)
{

}

bool AWhiteChessFigure::CanMove(FVector Direction)
{
	return false;
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackChessFigure.h"

// Sets default values
ABlackChessFigure::ABlackChessFigure()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABlackChessFigure::AttackKing()
{
	
}

void ABlackChessFigure::MoveUnderAttack()
{

}

// Called when the game starts or when spawned
void ABlackChessFigure::BeginPlay()
{
	Super::BeginPlay();
	
}

bool ABlackChessFigure::LineTrace(FVector Direction)
{
	return false;
}

void ABlackChessFigure::ShowLocations()
{

}

void ABlackChessFigure::TurnOffLocations()
{

}

// Called every frame
void ABlackChessFigure::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlackChessFigure::move(FVector Direction)
{

}

bool ABlackChessFigure::CanMove(FVector Direction)
{
	return false;
}

UStaticMeshComponent* ABlackChessFigure::GetMesh()
{
	return nullptr;
}

bool ABlackChessFigure::CanAttack(FVector Direction)
{
	return false;
}

void ABlackChessFigure::Attack(AWhiteChessFigure* WhiteFigure)
{

}
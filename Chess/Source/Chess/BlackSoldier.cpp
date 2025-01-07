// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackSoldier.h"
#include "OnePeaceOfBoard.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include <Kismet/GameplayStatics.h>
#include "Components/PointLightComponent.h"
#include "ChangeFidureWidget.h"
#include "WhiteKing.h"
#include "BlackKing.h"
#include "BlackSoldierChangeFigure.h"

void ABlackSoldier::ShowLocations()
{
	int possibleX;

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOnePeaceOfBoard::StaticClass(), FoundActors);

	if (index == 0)
	{
		possibleX = GetActorLocation().X - 2500;
	}
	else
	{
		possibleX = GetActorLocation().X - 1500;
	}

	for (AActor* Actor : FoundActors)
	{
		AOnePeaceOfBoard* BoardPiece = Cast<AOnePeaceOfBoard>(Actor);
		if (BoardPiece)
		{
			if (BlackKing->IsUnderAttack == false)
			{
				FVector Direction = BoardPiece->GetActorLocation();
				if (Direction.X >= possibleX && Direction.X < GetActorLocation().X - 500 &&
					Direction.Y >= GetActorLocation().Y - 500 && Direction.Y <= GetActorLocation().Y + 500)
				{
					if (BoardPiece->Light)
					{
						BoardPiece->Light->SetVisibility(true);
					}
				}
				if (CanAttack(Direction))
				{
					BoardPiece->Light->SetLightColor(AttackColor);
					BoardPiece->Light->SetVisibility(true);
				}
			}
			else
			{
				bool IsValidField = false;

				FVector Direction = BoardPiece->GetActorLocation();

				for (FVector TempDirection : BlackKing->PossibleAttackDirections)
				{
					FVector Difference1 = Direction - TempDirection;
					if ((FMath::Abs(Difference1.X) <= 500 and FMath::Abs(Difference1.Y) <= 500))
					{
						IsValidField = true;
					}
					if (IsValidField)
					{
						FVector CurrentLocation = GetActorLocation();

						FVector Difference = Direction - CurrentLocation;

						if (LineTrace(FVector(Direction.X, Direction.Y, GetActorLocation().Z)))
						{
							bool bIsValidMove = Direction.X >= possibleX && Direction.X < GetActorLocation().X - 500 &&
								Direction.Y >= GetActorLocation().Y - 500 && Direction.Y <= GetActorLocation().Y + 500;

							if (bIsValidMove)
							{
								BoardPiece->Light->SetVisibility(true);
							}
						}
					}
				}
			}
		}
	}
}

void ABlackSoldier::TurnOffLocations()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOnePeaceOfBoard::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		AOnePeaceOfBoard* BoardPiece = Cast<AOnePeaceOfBoard>(Actor);
		if (BoardPiece)
		{
			BoardPiece->Light->SetVisibility(false);
			BoardPiece->Light->SetLightColor(UsualColor);
		}
	}
}

bool ABlackSoldier::LineTrace(FVector Direction)
{
	bool SpaceIsFree = true;

	FVector Start = GetActorLocation();
	FVector End = Direction;

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	FHitResult OutHit;

	bool bIsHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams);

	if (bIsHit)
	{
		ABlackChessFigure* HitActor = Cast<ABlackChessFigure>(OutHit.GetActor());
		AWhiteChessFigure* WhiteFigure = Cast<AWhiteChessFigure>(OutHit.GetActor());

		if (HitActor)
		{
			SpaceIsFree = false;
		}
		else if(WhiteFigure)
		{
			SpaceIsFree = false;
		}
	}

	return SpaceIsFree;
}

void ABlackSoldier::move(FVector Direction)
{
	int possibleX;

	if (index == 0)
	{
		possibleX = GetActorLocation().X - 2500;
	}
	else
	{
		possibleX = GetActorLocation().X - 1500;
	}

	bool IsValidField = false;

	if (BlackKing->IsUnderAttack == false)
	{
		FVector CurrentLocation = GetActorLocation();

		FVector Difference = Direction - CurrentLocation;

		if (LineTrace(FVector(Direction.X, Direction.Y, GetActorLocation().Z)))
		{
			bool bIsValidMove = Direction.X >= possibleX && Direction.X < GetActorLocation().X - 500 &&
				Direction.Y >= GetActorLocation().Y - 500 && Direction.Y <= GetActorLocation().Y + 500;

			if (bIsValidMove)
			{
				SetActorLocation(Direction);
				moved = true;
			}
		}
	}
	else
	{
		for (FVector TempDirection : BlackKing->PossibleAttackDirections)
		{
			FVector Difference1 = Direction - TempDirection;
			if ((FMath::Abs(Difference1.X) <= 500 and FMath::Abs(Difference1.Y) <= 500))
			{
				IsValidField = true;
			}
			if (IsValidField)
			{
				FVector CurrentLocation = GetActorLocation();

				FVector Difference = Direction - CurrentLocation;

				if (LineTrace(FVector(Direction.X, Direction.Y, GetActorLocation().Z)))
				{
					bool bIsValidMove = Direction.X >= possibleX && Direction.X < GetActorLocation().X - 500 &&
						Direction.Y >= GetActorLocation().Y - 500 && Direction.Y <= GetActorLocation().Y + 500;

					if (bIsValidMove)
					{
						SetActorLocation(Direction);
						moved = true;
					}
				}
			}
		}
	}

	if (GetActorLocation().X < 900)
	{
		if (ChangeSoldierRef)
		{
			ChangeSoldierRef->SetSoldier(this);
			ChangeSoldierRef->AddToViewport();
		}
	}

	if (Material)
	{
		Mesh->SetMaterial(0, Material);
	}

	if (moved)
	{
		BlackKing->IsUnderAttack = false;
		BlackKing->PossibleAttackDirections.Empty();
		BlackKing->NumberOfMovesUnderAttack = 0;
		++index;
	}
}

bool ABlackSoldier::CanAttack(FVector Direction)
{
	bool bIsValidMove = false;
	bool bCanAttack = false;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWhiteChessFigure::StaticClass(), FoundActors);

	if (BlackKing->IsUnderAttack == false)
	{
		for (AActor* Actor : FoundActors)
		{
			AWhiteChessFigure* WhiteFigure = Cast<AWhiteChessFigure>(Actor);

			AWhiteKing* WhiteKing = Cast<AWhiteKing>(WhiteFigure);

			if (WhiteKing)
			{
				continue;
			}
			else
			{
				bCanAttack = (FMath::Abs(WhiteFigure->GetActorLocation().X - Direction.X) <= 500 and
					FMath::Abs(WhiteFigure->GetActorLocation().Y - Direction.Y) <= 500);

				if (bCanAttack)
				{
					break;
				}
			}
		}
	}
	else
	{
		for (AActor* Actor : FoundActors)
		{
			AWhiteChessFigure* WhiteFigure = Cast<AWhiteChessFigure>(Actor);

			AWhiteKing* WhiteKing = Cast<AWhiteKing>(WhiteFigure);

			if (WhiteKing)
			{
				continue;
			}
			else
			{
				for (FVector TempDirection : BlackKing->PossibleAttackDirections)
				{
					if ((FMath::Abs(TempDirection.X - Direction.X) <= 500 and
						FMath::Abs(TempDirection.Y - Direction.Y) <= 500))
					{
						bCanAttack = (FMath::Abs(WhiteFigure->GetActorLocation().X - Direction.X) <= 500 and
							FMath::Abs(WhiteFigure->GetActorLocation().Y - Direction.Y) <= 500);
					}

					if (bCanAttack)
					{
						BlackKing->IsUnderAttack = false;
						BlackKing->PossibleAttackDirections.Empty();
						break;
					}
				}
			}
		}
	}

	if (bCanAttack)
	{
		FVector CurrentLocation = GetActorLocation();
		bIsValidMove = (FMath::Abs(Direction.Y - (CurrentLocation.Y - 1000)) <= 200 &&
			FMath::Abs(Direction.X - (CurrentLocation.X - 1000)) <= 200) ||
			(FMath::Abs(Direction.Y - (CurrentLocation.Y - 1000)) <= 200 &&
				FMath::Abs(Direction.X - (CurrentLocation.X - 1000)) <= 200);
	}

	return bIsValidMove;
}

void ABlackSoldier::Attack(AWhiteChessFigure* WhiteFigure)
{
	FVector AttackDirection = WhiteFigure->GetActorLocation();

	if (CanAttack(AttackDirection))
	{
		SetActorLocation(AttackDirection);
		TurnOffLocations();
		WhiteFigure->SetActorHiddenInGame(true);
		WhiteFigure->SetActorEnableCollision(false);
		WhiteFigure->IsDead = true;
		moved = true;
		BlackKing->IsUnderAttack = false;
		BlackKing->PossibleAttackDirections.Empty();
		BlackKing->NumberOfMovesUnderAttack = 0;
		if (Material)
		{
			Mesh->SetMaterial(0, Material);
		}
		if (GetActorLocation().X < 900)
		{
			if (ChangeSoldierRef)
			{
				ChangeSoldierRef->SetSoldier(this);
				ChangeSoldierRef->AddToViewport();
			}
		}
	}
}

bool ABlackSoldier::CanMove(FVector Direction)
{	
	int	possibleX = 0;
	if (index == 0)
	{
		possibleX = GetActorLocation().X - 2000;
	}
	else
	{
		possibleX = GetActorLocation().X - 1000;
	}
	return (Direction.X >= possibleX and Direction.X < GetActorLocation().X - 500 and
		Direction.Y >= GetActorLocation().Y - 500 and Direction.Y <= GetActorLocation().Y + 500);
}

bool ABlackSoldier::WillOpenChack()
{
	BlackKing->IsUnderAttack = false;
	BlackKing->PossibleAttackDirections.Empty();
	bool ChackWillOpen = false;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWhiteChessFigure::StaticClass(), FoundActors);
	this->SetActorEnableCollision(false);
	for (AActor* Figure : FoundActors)
	{
		AWhiteChessFigure* WhiteFigure = Cast<AWhiteChessFigure>(Figure);
		if (WhiteFigure)
		{
			WhiteFigure->AttackKing();
			if (BlackKing->IsUnderAttack == true)
			{
				ChackWillOpen = true;
				break;
			}
		}
	}
	this->SetActorEnableCollision(true);
	return ChackWillOpen;
}

void ABlackSoldier::AttackKing()
{
	TArray<AActor*> Kings;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWhiteKing::StaticClass(), Kings);

	AWhiteKing* WhiteKing = Cast<AWhiteKing>(Kings[0]);

	if (WhiteKing)
	{
		FVector Direction = WhiteKing->GetActorLocation();

		FVector CurrentLocation = GetActorLocation();

		bool CanAttack = (FMath::Abs(Direction.Y - (CurrentLocation.Y + 1000)) <= 200 &&
			FMath::Abs(Direction.X - (CurrentLocation.X + 1000)) <= 200) ||
			(FMath::Abs(Direction.Y - (CurrentLocation.Y - 1000)) <= 200 &&
				FMath::Abs(Direction.X - (CurrentLocation.X + 1000)) <= 200);

		if (CanAttack)
		{
			WhiteKing->IsUnderAttack = true;
			WhiteKing->PossibleAttackDirections.Add(GetActorLocation());
		}

		if (WhiteKing->IsUnderAttack)
		{
			TArray<AActor*> WhiteFigures;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWhiteChessFigure::StaticClass(), WhiteFigures);

			for (AActor* WhiteFigure : WhiteFigures)
			{
				AWhiteChessFigure* TempWhiteFigure = Cast<AWhiteChessFigure>(WhiteFigure);
				TempWhiteFigure->MoveUnderAttack();
			}
		}

		if (WhiteKing->NumberOfMovesUnderAttack == 0 and WhiteKing->IsUnderAttack)
		{
			UGameplayStatics::OpenLevel(GetWorld(), FName("BlackWinner"));
		}
	}
}

void ABlackSoldier::MoveUnderAttack()
{	
	if (!IsDead)
	{
		if (BlackKing->IsUnderAttack)
		{
			bool bIsValidMove = false;
			for (FVector TempDirection : BlackKing->PossibleAttackDirections)
			{
				if (LineTrace(TempDirection))
				{
					bIsValidMove = CanMove(TempDirection);
					if (bIsValidMove)
					{	
						++BlackKing->NumberOfMovesUnderAttack;
					}
				}
			}
		}
		else
		{
			BlackKing->NumberOfMovesUnderAttack = 0;
		}
	}
}

ABlackSoldier::ABlackSoldier()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}

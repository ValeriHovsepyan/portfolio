// Fill out your copyright notice in the Description page of Project Settings.


#include "whiteSoldier.h"
#include "OnePeaceOfBoard.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include <Kismet/GameplayStatics.h>
#include "Components/PointLightComponent.h"
#include "ChangeFidureWidget.h"
#include "BlackChessFigure.h"
#include "BlackKing.h"
#include "WhiteKing.h"

void AwhiteSoldier::ShowLocations()
{
	int possibleX;

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOnePeaceOfBoard::StaticClass(), FoundActors);

	if (index == 0)
	{
		possibleX = GetActorLocation().X + 2500;
	}
	else
	{
		possibleX = GetActorLocation().X + 1500;
	}

	for (AActor* Actor : FoundActors)
	{
		AOnePeaceOfBoard* BoardPiece = Cast<AOnePeaceOfBoard>(Actor);
		if (BoardPiece)
		{	
			if (WhiteKing->IsUnderAttack == false)
			{
				FVector Direction = BoardPiece->GetActorLocation();
				if (Direction.X <= possibleX && Direction.X > GetActorLocation().X + 500 &&
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

				for (FVector TempDirection : WhiteKing->PossibleAttackDirections)
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
							bool bIsValidMove = Direction.X <= possibleX && Direction.X > GetActorLocation().X + 500 &&
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

void AwhiteSoldier::TurnOffLocations()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOnePeaceOfBoard::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		AOnePeaceOfBoard* BoardPiece = Cast<AOnePeaceOfBoard>(Actor);
		if (BoardPiece)
		{
			BoardPiece->Light->SetLightColor(UsualColor);
			BoardPiece->Light->SetVisibility(false);
		}
	}
}

bool AwhiteSoldier::LineTrace(FVector Direction)
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
		AWhiteChessFigure* HitActor = Cast<AWhiteChessFigure>(OutHit.GetActor());
		if (HitActor and HitActor != this)
		{
			SpaceIsFree = false;
		}
	}

	return SpaceIsFree;
}

void AwhiteSoldier::move(FVector Direction)
{	
	int possibleX;

	if (index == 0)
	{
		possibleX = GetActorLocation().X + 2000;
	}
	else
	{
		possibleX = GetActorLocation().X + 1500;
	}

	bool IsValidField = false;

	if (WhiteKing->IsUnderAttack == false)
	{
		FVector CurrentLocation = GetActorLocation();

		FVector Difference = Direction - CurrentLocation;

		if (LineTrace(FVector(Direction.X, Direction.Y, GetActorLocation().Z)))
		{
			bool bIsValidMove = Direction.X <= possibleX && Direction.X > GetActorLocation().X + 500 &&
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
		for (FVector TempDirection : WhiteKing->PossibleAttackDirections)
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
					bool bIsValidMove = Direction.X <= possibleX && Direction.X > GetActorLocation().X + 500 &&
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

	if (GetActorLocation().X > 7100)
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
		WhiteKing->IsUnderAttack = false;
		WhiteKing->PossibleAttackDirections.Empty();
		WhiteKing->NumberOfMovesUnderAttack = 0;
		++index;
	}
}

AwhiteSoldier::AwhiteSoldier()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}

bool AwhiteSoldier::CanAttack(FVector Direction)
{
	bool bIsValidMove = false;
	bool bCanAttack = false;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABlackChessFigure::StaticClass(), FoundActors);

	if (WhiteKing->IsUnderAttack == false)
	{
		for (AActor* Actor : FoundActors)
		{
			ABlackChessFigure* BlackFigure = Cast<ABlackChessFigure>(Actor);

			ABlackKing* BlackKing = Cast<ABlackKing>(BlackFigure);

			if (BlackKing)
			{
				continue;
			}
			else
			{
				bCanAttack = (FMath::Abs(BlackFigure->GetActorLocation().X - Direction.X) <= 500 and
					FMath::Abs(BlackFigure->GetActorLocation().Y - Direction.Y) <= 500);

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
			ABlackChessFigure* BlackFigure = Cast<ABlackChessFigure>(Actor);

			ABlackKing* BlackKing = Cast<ABlackKing>(BlackFigure);

			if (BlackKing)
			{
				continue;
			}
			else
			{	
				for (FVector TempDirection : WhiteKing->PossibleAttackDirections)
				{	
					if ((FMath::Abs(TempDirection.X - Direction.X) <= 500 and
						FMath::Abs(TempDirection.Y - Direction.Y) <= 500))
					{
						bCanAttack = (FMath::Abs(BlackFigure->GetActorLocation().X - Direction.X) <= 500 and
							FMath::Abs(BlackFigure->GetActorLocation().Y - Direction.Y) <= 500);
					}

					if (bCanAttack)
					{	
						WhiteKing->IsUnderAttack = false;
						WhiteKing->PossibleAttackDirections.Empty();
						break;
					}
				}
			}
		}
	}

	if (bCanAttack)
	{
		FVector CurrentLocation = GetActorLocation();
		bIsValidMove = (FMath::Abs(Direction.Y - (CurrentLocation.Y + 1000)) <= 200 &&
			FMath::Abs(Direction.X - (CurrentLocation.X + 1000)) <= 200) ||
			(FMath::Abs(Direction.Y - (CurrentLocation.Y - 1000)) <= 200 &&
				FMath::Abs(Direction.X - (CurrentLocation.X + 1000)) <= 200);
	}

	return bIsValidMove;
}

void AwhiteSoldier::Attack(ABlackChessFigure* BlackFigure)
{	
	FVector AttackDirection = BlackFigure->GetActorLocation();

	if (CanAttack(AttackDirection))
	{
		SetActorLocation(AttackDirection);
		TurnOffLocations();
		BlackFigure->SetActorHiddenInGame(true);
		BlackFigure->SetActorEnableCollision(false);
		BlackFigure->IsDead = true;
		moved = true;
		++index;
		WhiteKing->NumberOfMovesUnderAttack = 0;
		if (Material)
		{
			Mesh->SetMaterial(0, Material);
		}
		if (GetActorLocation().X > 7100)
		{
			if (ChangeSoldierRef)
			{
				ChangeSoldierRef->SetSoldier(this);
				ChangeSoldierRef->AddToViewport();
			}
		}
	}
}

bool AwhiteSoldier::WillOpenChack()
{
	WhiteKing->IsUnderAttack = false;
	WhiteKing->PossibleAttackDirections.Empty();
	bool ChackWillOpen = false;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABlackChessFigure::StaticClass(), FoundActors);
	this->SetActorEnableCollision(false);
	for (AActor* Figure : FoundActors)
	{
		ABlackChessFigure* BlackFigure = Cast<ABlackChessFigure>(Figure);
		if (BlackFigure)
		{
			BlackFigure->AttackKing();
			if (WhiteKing->IsUnderAttack == true)
			{
				ChackWillOpen = true;
				break;
			}
		}
	}
	this->SetActorEnableCollision(true);
	return ChackWillOpen;
}

void AwhiteSoldier::MoveUnderAttack()
{	
	if (!IsDead)
	{
		if (WhiteKing->IsUnderAttack)
		{
			bool bIsValidMove = false;
			for (FVector TempDirection : WhiteKing->PossibleAttackDirections)
			{
				if (LineTrace(TempDirection))
				{
					bIsValidMove = CanMove(TempDirection);
					if (bIsValidMove)
					{
						++WhiteKing->NumberOfMovesUnderAttack;
					}
				}
			}
		}
		else
		{
			WhiteKing->NumberOfMovesUnderAttack = 0;
		}
	}
}

void AwhiteSoldier::AttackKing()
{
	TArray<AActor*> Kings;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABlackKing::StaticClass(), Kings);

	ABlackKing* BlackKing = Cast<ABlackKing>(Kings[0]);

	if (BlackKing)
	{	
		FVector Direction = BlackKing->GetActorLocation();

		FVector CurrentLocation = GetActorLocation();

		bool CanAttack = (FMath::Abs(Direction.Y - (CurrentLocation.Y + 1000)) <= 200 &&
			FMath::Abs(Direction.X - (CurrentLocation.X + 1000)) <= 200) ||
			(FMath::Abs(Direction.Y - (CurrentLocation.Y - 1000)) <= 200 &&
				FMath::Abs(Direction.X - (CurrentLocation.X + 1000)) <= 200);

		if (CanAttack)
		{
			BlackKing->IsUnderAttack = true;
			BlackKing->PossibleAttackDirections.Add(GetActorLocation());
			if (BlackKing->AttackUnderChack(this))
			{
				++BlackKing->NumberOfMovesUnderAttack;
			}
		}
		if (BlackKing->IsUnderAttack)
		{
			TArray<AActor*> BlackFigures;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABlackChessFigure::StaticClass(), BlackFigures);

			for (AActor* BlackFigure : BlackFigures)
			{
				ABlackChessFigure* TempBlackFigure = Cast<ABlackChessFigure>(BlackFigure);
				TempBlackFigure->MoveUnderAttack();
			}
		}

		if (BlackKing->NumberOfMovesUnderAttack == 0 and BlackKing->IsUnderAttack)
		{
			UGameplayStatics::OpenLevel(GetWorld(), FName("WhiteWinner"));
		}
	}
}

bool AwhiteSoldier::CanMove(FVector Direction)
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
// Fill out your copyright notice in the Description page of Project Settings.


#include "WhiteKnight.h"
#include "OnePeaceOfBoard.h"
#include "Components/PointLightComponent.h"
#include <Kismet/GameplayStatics.h>
#include "BlackChessFigure.h"
#include "BlackKing.h"
#include "WhiteKing.h"

void AWhiteKnight::move(FVector Direction)
{
	bool bIsValidMove = false;
	if (WhiteKing and WhiteKing->IsUnderAttack == false)
	{
		bIsValidMove = CanMove(Direction);

		if (bIsValidMove)
		{
			SetActorLocation(Direction);
			moved = true;
		}
	}
	else if (WhiteKing)
	{
		for (FVector TempDirection : WhiteKing->PossibleAttackDirections)
		{
			FVector Difference = Direction - TempDirection;

			if (FMath::Abs(Difference.X) < 500 and FMath::Abs(Difference.Y) < 500)
			{
				bIsValidMove = CanMove(Direction);
				break;
			}
		}

		if (bIsValidMove)
		{
			SetActorLocation(Direction);
			WhiteKing->IsUnderAttack = false;
			WhiteKing->PossibleAttackDirections.Empty();
			moved = true;
		}
	}

	if (Material)
	{
		Mesh->SetMaterial(0, Material);
	}

	if (moved)
	{
		AttackKing();
		WhiteKing->NumberOfMovesUnderAttack = 0;
	}
}

void AWhiteKnight::ShowLocations()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOnePeaceOfBoard::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		AOnePeaceOfBoard* BoardPiece = Cast<AOnePeaceOfBoard>(Actor);
		if (BoardPiece)
		{
			if (WhiteKing->IsUnderAttack == false)
			{	
				FVector CurrentLocation = GetActorLocation();

				FVector Direction = BoardPiece->GetActorLocation();

				FVector Difference = Direction - CurrentLocation;

				bool bIsValidMove = ((FMath::Abs(Difference.X) >= 1200 && FMath::Abs(Difference.X) <= 2400)
					&& FMath::Abs(Difference.Y) <= 1200 && FMath::Abs(Difference.Y) >= 800) ||
					((FMath::Abs(Difference.X) <= 1200 && FMath::Abs(Difference.X) >= 800)
						&& FMath::Abs(Difference.Y) >= 1200 && FMath::Abs(Difference.Y) <= 2400);

				if (bIsValidMove)
				{
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

						bool bIsValidMove = ((FMath::Abs(Difference.X) >= 1200 && FMath::Abs(Difference.X) <= 2400)
							&& FMath::Abs(Difference.Y) <= 1200 && FMath::Abs(Difference.Y) >= 800) ||
							((FMath::Abs(Difference.X) <= 1200 && FMath::Abs(Difference.X) >= 800)
								&& FMath::Abs(Difference.Y) >= 1200 && FMath::Abs(Difference.Y) <= 2400);

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

void AWhiteKnight::TurnOffLocations()
{
	FVector Direction;

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOnePeaceOfBoard::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		AOnePeaceOfBoard* BoardPiece = Cast<AOnePeaceOfBoard>(Actor);
		if (BoardPiece)
		{
			BoardPiece->Light->SetVisibility(false);
		}
	}
}

bool AWhiteKnight::CanAttack(FVector Direction)
{
	bool bIsValidMove = false;
	bool bbCanAttack = false;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABlackChessFigure::StaticClass(), FoundActors);
	if (WhiteKing and WhiteKing->IsUnderAttack == false)
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
				bbCanAttack = (FMath::Abs(BlackFigure->GetActorLocation().X - Direction.X) <= 500 and
					FMath::Abs(BlackFigure->GetActorLocation().Y - Direction.Y) <= 500);

				if (bbCanAttack)
				{
					break;
				}
			}
		}
	}
	else if (WhiteKing)
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
						bbCanAttack = (FMath::Abs(BlackFigure->GetActorLocation().X - Direction.X) <= 500 and
							FMath::Abs(BlackFigure->GetActorLocation().Y - Direction.Y) <= 500);

						if (bbCanAttack)
						{
							WhiteKing->IsUnderAttack = false;
							WhiteKing->PossibleAttackDirections.Empty();
							break;
						}
					}
				}
				if (bbCanAttack)
				{
					break;
				}
			}
		}
	}

	if (bbCanAttack)
	{
		FVector CurrentLocation = GetActorLocation();
		FVector Difference = Direction - CurrentLocation;
		bIsValidMove = ((FMath::Abs(Difference.X) >= 1200 && FMath::Abs(Difference.X) <= 2400)
			&& FMath::Abs(Difference.Y) <= 1200 && FMath::Abs(Difference.Y) >= 800) ||
			((FMath::Abs(Difference.X) <= 1200 && FMath::Abs(Difference.X) >= 800)
				&& FMath::Abs(Difference.Y) >= 1200 && FMath::Abs(Difference.Y) <= 2400);
	}

	return bIsValidMove;
}

void AWhiteKnight::Attack(ABlackChessFigure* BlackFigure)
{
	FVector AttackDirection = BlackFigure->GetActorLocation();

	if (CanAttack(AttackDirection))
	{
		SetActorLocation(FVector(AttackDirection.X, AttackDirection.Y, GetActorLocation().Z));
		TurnOffLocations();
		BlackFigure->SetActorHiddenInGame(true);
		BlackFigure->SetActorEnableCollision(false);
		BlackFigure->IsDead = true;
		moved = true;
		WhiteKing->NumberOfMovesUnderAttack = 0;
		WhiteKing->IsUnderAttack = false;
		WhiteKing->PossibleAttackDirections.Empty();
		AttackKing();
		if (Material)
		{
			Mesh->SetMaterial(0, Material);
		}
	}
}

bool AWhiteKnight::CanMove(FVector Direction)
{	
	FVector CurrentLocation = GetActorLocation();

	FVector Difference = Direction - CurrentLocation;

	return ((FMath::Abs(Difference.X) >= 1200 && FMath::Abs(Difference.X) <= 2400)
		&& FMath::Abs(Difference.Y) <= 1200 && FMath::Abs(Difference.Y) >= 800) ||
		((FMath::Abs(Difference.X) <= 1200 && FMath::Abs(Difference.X) >= 800)
			&& FMath::Abs(Difference.Y) >= 1200 && FMath::Abs(Difference.Y) <= 2400);
}

void AWhiteKnight::AttackKing()
{
	TArray<AActor*> Kings;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABlackKing::StaticClass(), Kings);

	ABlackKing* BlackKing = Cast<ABlackKing>(Kings[0]);

	if (BlackKing)
	{
		FVector CurrentLocation = GetActorLocation();

		FVector Difference = BlackKing->GetActorLocation() - CurrentLocation;

		bool bIsValidMove = ((FMath::Abs(Difference.X) >= 1200 && FMath::Abs(Difference.X) <= 2400)
			&& FMath::Abs(Difference.Y) <= 1200 && FMath::Abs(Difference.Y) >= 800) ||
			((FMath::Abs(Difference.X) <= 1200 && FMath::Abs(Difference.X) >= 800)
				&& FMath::Abs(Difference.Y) >= 1200 && FMath::Abs(Difference.Y) <= 2400);

		if (bIsValidMove)
		{	
			BlackKing->IsUnderAttack = true;
			BlackKing->PossibleAttackDirections.Add(GetActorLocation());
		}

		if (BlackKing->IsUnderAttack)
		{
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

bool AWhiteKnight::LineTrace(FVector Direction)
{	
	bool SpaceIsfree = false;

	FVector CurrentLocation = GetActorLocation();

	FVector Difference = Direction - CurrentLocation;

	bool bIsvalidMove = ((FMath::Abs(Difference.X) >= 1200 && FMath::Abs(Difference.X) <= 2400)
		&& FMath::Abs(Difference.Y) <= 1200 && FMath::Abs(Difference.Y) >= 800) ||
		((FMath::Abs(Difference.X) <= 1200 && FMath::Abs(Difference.X) >= 800)
			&& FMath::Abs(Difference.Y) >= 1200 && FMath::Abs(Difference.Y) <= 2400);

	if (bIsvalidMove)
	{
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
				SpaceIsfree = false;
				HitActor->IsSafe = true;
			}
		}
	}
	return SpaceIsfree;
}

bool AWhiteKnight::WillOpenChack()
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

void AWhiteKnight::MoveUnderAttack()
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

AWhiteKnight::AWhiteKnight()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}

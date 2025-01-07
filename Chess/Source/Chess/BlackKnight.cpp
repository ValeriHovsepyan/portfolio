// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackKnight.h"

#include "OnePeaceOfBoard.h"
#include "Components/PointLightComponent.h"
#include <Kismet/GameplayStatics.h>
#include "WhiteKing.h"
#include "BlackKing.h"

void ABlackKnight::move(FVector Direction)
{
	bool bIsValidMove = false;
	if (BlackKing and BlackKing->IsUnderAttack == false)
	{
		bIsValidMove = CanMove(Direction);

		if (bIsValidMove)
		{
			SetActorLocation(Direction);
			moved = true;
		}
	}
	else if (BlackKing)
	{
		for (FVector TempDirection : BlackKing->PossibleAttackDirections)
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
			BlackKing->IsUnderAttack = false;
			BlackKing->PossibleAttackDirections.Empty();
			moved = true;
		}
	}

	if (Material)
	{
		Mesh->SetMaterial(0, Material);
	}

	if (moved)
	{
		BlackKing->NumberOfMovesUnderAttack = 0;
	}

	AttackKing();
}

void ABlackKnight::ShowLocations()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOnePeaceOfBoard::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		AOnePeaceOfBoard* BoardPiece = Cast<AOnePeaceOfBoard>(Actor);
		if (BoardPiece)
		{
			if (BlackKing->IsUnderAttack == false)
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

void ABlackKnight::TurnOffLocations()
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

bool ABlackKnight::CanAttack(FVector Direction)
{
	bool bIsValidMove = false;
	bool bbCanAttack = false;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWhiteChessFigure::StaticClass(), FoundActors);
	if (BlackKing and BlackKing->IsUnderAttack == false)
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
				bbCanAttack = (FMath::Abs(WhiteFigure->GetActorLocation().X - Direction.X) <= 500 and
					FMath::Abs(WhiteFigure->GetActorLocation().Y - Direction.Y) <= 500);

				if (bbCanAttack)
				{
					break;
				}
			}
		}
	}
	else if (BlackKing)
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
						bbCanAttack = (FMath::Abs(WhiteFigure->GetActorLocation().X - Direction.X) <= 500 and
							FMath::Abs(WhiteFigure->GetActorLocation().Y - Direction.Y) <= 500);

						if (bbCanAttack)
						{
							BlackKing->IsUnderAttack = false;
							BlackKing->PossibleAttackDirections.Empty();
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

void ABlackKnight::Attack(AWhiteChessFigure* WhiteFigure)
{
	FVector AttackDirection = WhiteFigure->GetActorLocation();

	if (CanAttack(AttackDirection))
	{
		SetActorLocation(FVector(AttackDirection.X, AttackDirection.Y, GetActorLocation().Z));
		TurnOffLocations();
		WhiteFigure->SetActorHiddenInGame(true);
		WhiteFigure->SetActorEnableCollision(false);
		WhiteFigure->IsDead = true;
		moved = true;
		if (Material)
		{
			Mesh->SetMaterial(0, Material);
		}
		BlackKing->NumberOfMovesUnderAttack = 0;
		AttackKing();
	}
}

bool ABlackKnight::CanMove(FVector Direction)
{	
	FVector CurrentLocation = GetActorLocation();

	FVector Difference = Direction - CurrentLocation;

	return ((FMath::Abs(Difference.X) >= 1200 && FMath::Abs(Difference.X) <= 2400)
		&& FMath::Abs(Difference.Y) <= 1200 && FMath::Abs(Difference.Y) >= 800) ||
		((FMath::Abs(Difference.X) <= 1200 && FMath::Abs(Difference.X) >= 800)
			&& FMath::Abs(Difference.Y) >= 1200 && FMath::Abs(Difference.Y) <= 2400);
}

void ABlackKnight::AttackKing()
{
	TArray<AActor*> Kings;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWhiteKing::StaticClass(), Kings);

	AWhiteKing* WhiteKing = Cast<AWhiteKing>(Kings[0]);

	if (WhiteKing)
	{
		FVector Difference = WhiteKing->GetActorLocation() - GetActorLocation();

		bool bIsValidMove = ((FMath::Abs(Difference.X) >= 1200 && FMath::Abs(Difference.X) <= 2400)
			&& FMath::Abs(Difference.Y) <= 1200 && FMath::Abs(Difference.Y) >= 800) ||
			((FMath::Abs(Difference.X) <= 1200 && FMath::Abs(Difference.X) >= 800)
				&& FMath::Abs(Difference.Y) >= 1200 && FMath::Abs(Difference.Y) <= 2400);

		if (bIsValidMove)
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
	}

	if (WhiteKing->IsUnderAttack)
	{
		WhiteKing->PossibleAttackDirections.Add(GetActorLocation());
		if (WhiteKing->AttackUnderChack(this))
		{
			++WhiteKing->NumberOfMovesUnderAttack;
		}
	}

	if (WhiteKing->NumberOfMovesUnderAttack == 0 and WhiteKing->IsUnderAttack)
	{
		UGameplayStatics::OpenLevel(GetWorld(), FName("BlackWinner"));
	}
}

bool ABlackKnight::WillOpenChack()
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

bool ABlackKnight::LineTrace(FVector Direction)
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
			ABlackChessFigure* HitActor = Cast<ABlackChessFigure>(OutHit.GetActor());
			if (HitActor and HitActor != this)
			{
				SpaceIsfree = false;
				HitActor->IsSafe = true;
			}
		}
	}
	return SpaceIsfree;
}

void ABlackKnight::MoveUnderAttack()
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

ABlackKnight::ABlackKnight()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackElephant.h"
#include "OnePeaceOfBoard.h"
#include "Components/PointLightComponent.h"
#include <Kismet/GameplayStatics.h>
#include "WhiteKing.h"
#include "WhiteChessFigure.h"
#include "BlackKing.h"

bool ABlackElephant::LineTrace(FVector Direction)
{	
	m_CanAttackKing = false;
	bool SpaceIsFree = true;

	FVector Start = GetActorLocation();
	FVector End = Direction;

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	FHitResult OutHit;

	bool bIsHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams);

	if (bIsHit)
	{
		AWhiteChessFigure* WhiteFigure = Cast<AWhiteChessFigure>(OutHit.GetActor());
		ABlackChessFigure* BlackFigure = Cast<ABlackChessFigure>(OutHit.GetActor());
		AWhiteKing* WhiteKing = Cast<AWhiteKing>(OutHit.GetActor());

		if (BlackFigure)
		{
			SpaceIsFree = false;
			FVector CurrentLocation = GetActorLocation();

			FVector Difference = Direction - CurrentLocation;

			bool bIsValidMove = (FMath::Abs(Difference.X) >= 0 && FMath::Abs(Difference.X) < 500) ||
				(FMath::Abs(Difference.Y) >= 0 && FMath::Abs(Difference.Y) < 500);
			SpaceIsFree = false;

			if (bIsValidMove)
			{
				BlackFigure->IsSafe = true;
			}
		}
		else if (WhiteKing)
		{
			SpaceIsFree = false;
			m_CanAttackKing = true;
		}
		else if (WhiteFigure)
		{
			TArray<AActor*> FoundActors;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOnePeaceOfBoard::StaticClass(), FoundActors);

			for (AActor* Actor : FoundActors)
			{
				AOnePeaceOfBoard* BoardPiece = Cast<AOnePeaceOfBoard>(Actor);
				if (BoardPiece)
				{
					FVector CurrentLocation = GetActorLocation();

					FVector Difference = BoardPiece->GetActorLocation() - CurrentLocation;

					bool bIsValidMove = (FMath::Abs(Difference.X) >= 0 && FMath::Abs(Difference.X) < 500) ||
						(FMath::Abs(Difference.Y) >= 0 && FMath::Abs(Difference.Y) < 500);

					if (bIsValidMove)
					{
						FVector Difference1 = BoardPiece->GetActorLocation() - WhiteFigure->GetActorLocation();
						bool bIsValidField = (FMath::Abs(Difference1.X) <= 200 and FMath::Abs(Difference1.Y) <= 200);
						if (bIsValidField)
						{
							m_bCanAttack = true;
							BoardPiece->Light->SetLightColor(AttackColor);
							BoardPiece->Light->SetVisibility(true);
						}
					}
				}
			}
			SpaceIsFree = false;
		}
	}
	return SpaceIsFree;
}

void ABlackElephant::AttackKing()
{
	TArray<AActor*> Kings;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWhiteKing::StaticClass(), Kings);

	AWhiteKing* WhiteKing = Cast<AWhiteKing>(Kings[0]);
	
	if (WhiteKing)
	{	
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOnePeaceOfBoard::StaticClass(), FoundActors);
		for (AActor* Actor : FoundActors)
		{
			AOnePeaceOfBoard* BoardPiece = Cast<AOnePeaceOfBoard>(Actor);
			if (BoardPiece)
			{	
				if (LineTrace(WhiteKing->GetActorLocation()) or m_CanAttackKing)
				{
					if (LineTrace(BoardPiece->GetActorLocation()))
					{
						FVector CurrentLocation = GetActorLocation();

						FVector Difference = BoardPiece->GetActorLocation() - CurrentLocation;

						FVector ElephantLocation = GetActorLocation();
						FVector KingLocation = WhiteKing->GetActorLocation();
						FVector BoardPieceLocation = BoardPiece->GetActorLocation();

						bool IsInInterval = false;

						if (FMath::Abs(ElephantLocation.Y - KingLocation.Y) < 20)
						{
							IsInInterval = ((BoardPiece->GetActorLocation().X >= WhiteKing->GetActorLocation().X and BoardPiece->GetActorLocation().X < CurrentLocation.X
								or BoardPiece->GetActorLocation().X < WhiteKing->GetActorLocation().X and BoardPiece->GetActorLocation().X > CurrentLocation.X)
								and (BoardPiece->GetActorLocation().Y > WhiteKing->GetActorLocation().Y - 100 and BoardPiece->GetActorLocation().Y < CurrentLocation.Y + 100
									or BoardPiece->GetActorLocation().Y < WhiteKing->GetActorLocation().Y + 100 and BoardPiece->GetActorLocation().Y > CurrentLocation.Y + 100));
						}
						else if (FMath::Abs(ElephantLocation.X - KingLocation.X) < 20)
						{
							IsInInterval = ((BoardPiece->GetActorLocation().X > WhiteKing->GetActorLocation().X - 100 and BoardPiece->GetActorLocation().X < CurrentLocation.X + 100
								or BoardPiece->GetActorLocation().X < WhiteKing->GetActorLocation().X + 100 and BoardPiece->GetActorLocation().X > CurrentLocation.X - 100)
								and (BoardPiece->GetActorLocation().Y > WhiteKing->GetActorLocation().Y and BoardPiece->GetActorLocation().Y < CurrentLocation.Y
									or BoardPiece->GetActorLocation().Y < WhiteKing->GetActorLocation().Y and BoardPiece->GetActorLocation().Y > CurrentLocation.Y));
						}

						bool bIsValidMove = (FMath::Abs(Difference.X) >= 0 && FMath::Abs(Difference.X) < 500) ||
							(FMath::Abs(Difference.Y) >= 0 && FMath::Abs(Difference.Y) < 500);

						if (bIsValidMove and IsInInterval)
						{
							WhiteKing->PossibleAttackDirections.Add(BoardPiece->GetActorLocation());
							WhiteKing->IsUnderAttack = true;
						}
					}
				}
			}
		}
		if (WhiteKing->IsUnderAttack)
		{
			WhiteKing->PossibleAttackDirections.Add(GetActorLocation());
		}

		if (WhiteKing->IsUnderAttack)
		{
			WhiteKing->PossibleAttackDirections.Add(GetActorLocation());
			if (WhiteKing->AttackUnderChack(this))
			{
				++WhiteKing->NumberOfMovesUnderAttack;
			}
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
			if (WhiteKing->NumberOfMovesUnderAttack == 0 and WhiteKing->IsUnderAttack)
			{
				UGameplayStatics::OpenLevel(GetWorld(), FName("BlackWinner"));
			}
		}
	}
}

bool ABlackElephant::WillOpenChack()
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

void ABlackElephant::MoveUnderAttack()
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

void ABlackElephant::move(FVector Direction)
{
	if (LineTrace(FVector(Direction.X, Direction.Y, GetActorLocation().Z)))
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
	}
	if (Material)
	{
		Mesh->SetMaterial(0, Material);
	}
	if (moved)
	{	
		BlackKing->NumberOfMovesUnderAttack = 0;
		++index;
		AttackKing();
	}
}

void ABlackElephant::ShowLocations()
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

				if (LineTrace(FVector(Direction.X, Direction.Y, GetActorLocation().Z)))
				{
					bool bIsValidMove = (FMath::Abs(Difference.X) >= 0 && FMath::Abs(Difference.X) < 500) ||
						(FMath::Abs(Difference.Y) >= 0 && FMath::Abs(Difference.Y) < 500);

					if (bIsValidMove)
					{
						BoardPiece->Light->SetVisibility(true);
					}
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
							bool bIsValidMove = (FMath::Abs(Difference.X) >= 0 && FMath::Abs(Difference.X) < 500) ||
								(FMath::Abs(Difference.Y) >= 0 && FMath::Abs(Difference.Y) < 500);

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

void ABlackElephant::TurnOffLocations()
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

bool ABlackElephant::CanAttack(FVector Direction)
{	
	LineTrace(FVector(Direction.X, Direction.Y, GetActorLocation().Z));
	if (m_bCanAttack)
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
			bIsValidMove = (FMath::Abs(Difference.X) >= 0 && FMath::Abs(Difference.X) < 500) ||
				(FMath::Abs(Difference.Y) >= 0 && FMath::Abs(Difference.Y) < 500);
		}

		return bIsValidMove;
	}
	else
	{
		return false;
	}
}

void ABlackElephant::Attack(AWhiteChessFigure* WhiteFigure)
{
	FVector AttackDirection = WhiteFigure->GetActorLocation();
	FVector Start = GetActorLocation();
	FVector End = AttackDirection;

	End.Z = 300;

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	FHitResult OutHit;

	bool bIsHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams);

	AWhiteChessFigure* WhiteFigureHit = nullptr;

	if (bIsHit)
	{
		WhiteFigureHit = Cast<AWhiteChessFigure>(OutHit.GetActor());
	}

	if (WhiteFigureHit and WhiteFigureHit->GetName() == WhiteFigure->GetName())
	{
		if (CanAttack(AttackDirection))
		{
			SetActorLocation(AttackDirection);
			TurnOffLocations();
			WhiteFigure->SetActorHiddenInGame(true);
			WhiteFigure->SetActorEnableCollision(false);
			WhiteFigure->IsDead = true;
			moved = true;
			m_bCanAttack = false;
			BlackKing->NumberOfMovesUnderAttack = 0;
			if (Material)
			{
				Mesh->SetMaterial(0, Material);
			}
			AttackKing();
		}
	}
}

bool ABlackElephant::CanMove(FVector Direction)
{	
	if (LineTrace(Direction))
	{
		FVector CurrentLocation = GetActorLocation();

		FVector Difference = Direction - CurrentLocation;

		return (FMath::Abs(Difference.X) >= 0 && FMath::Abs(Difference.X) < 500) ||
			(FMath::Abs(Difference.Y) >= 0 && FMath::Abs(Difference.Y) < 500);
	}
	else
	{
		return false;
	}
}

ABlackElephant::ABlackElephant()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}

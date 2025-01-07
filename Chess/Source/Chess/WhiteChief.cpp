// Fill out your copyright notice in the Description page of Project Settings.


#include "WhiteChief.h"
#include "OnePeaceOfBoard.h"
#include "Components/PointLightComponent.h"
#include <Kismet/GameplayStatics.h>
#include "BlackChessFigure.h"
#include "BlackKing.h"
#include "WhiteKing.h"

bool AWhiteChief::LineTrace(FVector Direction)
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
		ABlackKing* BlackKing = Cast<ABlackKing>(OutHit.GetActor());

		if (WhiteFigure and WhiteFigure != this)
		{
			SpaceIsFree = false;
			FVector Difference = Direction - GetActorLocation();

			bool bIsValidMove = (FMath::Abs(Difference.X) >= FMath::Abs(Difference.Y) - 500)
				&& (FMath::Abs(Difference.X) <= FMath::Abs(Difference.Y) + 500);
			if (bIsValidMove)
			{
				WhiteFigure->IsSafe = true;
			}
		}
		else if (BlackKing)
		{
			SpaceIsFree = false;
			m_CanAttackKing = true;
		}
		else if (BlackFigure)
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

					bool bIsValidMove = (FMath::Abs(Difference.X) >= FMath::Abs(Difference.Y) - 500)
						&& (FMath::Abs(Difference.X) <= FMath::Abs(Difference.Y) + 500);

					if (bIsValidMove)
					{
						FVector Difference1 = BoardPiece->GetActorLocation() - BlackFigure->GetActorLocation();
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

void AWhiteChief::AttackKing()
{	
	TArray<AActor*> Kings;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABlackKing::StaticClass(), Kings);

	ABlackKing* BlackKing = Cast<ABlackKing>(Kings[0]);

	if (BlackKing)
	{
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOnePeaceOfBoard::StaticClass(), FoundActors);
		for (AActor* Actor : FoundActors)
		{
			AOnePeaceOfBoard* BoardPiece = Cast<AOnePeaceOfBoard>(Actor);
			if (BoardPiece)
			{	
				if (LineTrace(BlackKing->GetActorLocation()) or m_CanAttackKing)
				{
					if (LineTrace(BoardPiece->GetActorLocation()))
					{
						FVector CurrentLocation = GetActorLocation();

						FVector Difference = BoardPiece->GetActorLocation() - CurrentLocation;

						bool IsInInterval = ((BoardPiece->GetActorLocation().X >= BlackKing->GetActorLocation().X and BoardPiece->GetActorLocation().X < CurrentLocation.X
							or BoardPiece->GetActorLocation().X < BlackKing->GetActorLocation().X and BoardPiece->GetActorLocation().X > CurrentLocation.X)
							and (BoardPiece->GetActorLocation().Y > BlackKing->GetActorLocation().Y and BoardPiece->GetActorLocation().Y < CurrentLocation.Y
								or BoardPiece->GetActorLocation().Y < BlackKing->GetActorLocation().Y and BoardPiece->GetActorLocation().Y > CurrentLocation.Y));

						bool bIsValidMove = (FMath::Abs(Difference.X) >= FMath::Abs(Difference.Y) - 500)
							&& (FMath::Abs(Difference.X) <= FMath::Abs(Difference.Y) + 500);

						if (bIsValidMove and IsInInterval)
						{
							FVector Difference1 = BoardPiece->GetActorLocation() - BlackKing->GetActorLocation();

							if ((FMath::Abs(Difference1.X) >= FMath::Abs(Difference1.Y) - 500)
								&& (FMath::Abs(Difference1.X) <= FMath::Abs(Difference1.Y) + 500))
							{
								BlackKing->PossibleAttackDirections.Add(BoardPiece->GetActorLocation());
								BlackKing->IsUnderAttack = true;
							}
						}
					}
				}
			}
		}
		if (BlackKing->IsUnderAttack)
		{
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

void AWhiteChief::MoveUnderAttack()
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

void AWhiteChief::move(FVector Direction)
{	
	if (LineTrace(FVector(Direction.X, Direction.Y, GetActorLocation().Z)))
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

void AWhiteChief::ShowLocations()
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

				if (LineTrace(FVector(Direction.X, Direction.Y, GetActorLocation().Z)))
				{
					bool bIsValidMove = (FMath::Abs(Difference.X) >= FMath::Abs(Difference.Y) - 500)
						&& (FMath::Abs(Difference.X) <= FMath::Abs(Difference.Y) + 500);

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
							bool bIsValidMove = (FMath::Abs(Difference.X) >= FMath::Abs(Difference.Y) - 500)
								&& (FMath::Abs(Difference.X) <= FMath::Abs(Difference.Y) + 500);

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

void AWhiteChief::TurnOffLocations()
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

bool AWhiteChief::CanAttack(FVector Direction)
{	
	LineTrace(FVector(Direction.X, Direction.Y, GetActorLocation().Z));
	if (m_bCanAttack)
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
			bIsValidMove = (FMath::Abs(Difference.X) >= FMath::Abs(Difference.Y) - 500)
				&& (FMath::Abs(Difference.X) <= FMath::Abs(Difference.Y) + 500);
		}

		return bIsValidMove;
	}
	else
	{
		return false;
	}
}

void AWhiteChief::Attack(ABlackChessFigure* BlackFigure)
{
	FVector AttackDirection = BlackFigure->GetActorLocation();
	FVector Start = GetActorLocation();
	FVector End = AttackDirection;

	End.Z = 300;

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	FHitResult OutHit;

	bool bIsHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams);
	ABlackChessFigure* BlackFigureHit = nullptr;

	if (bIsHit)
	{
		BlackFigureHit = Cast<ABlackChessFigure>(OutHit.GetActor());
	}

	if (BlackFigureHit and BlackFigure->GetName() == BlackFigureHit->GetName())
	{
		if (CanAttack(AttackDirection))
		{
			SetActorLocation(FVector(AttackDirection.X, AttackDirection.Y, GetActorLocation().Z));
			TurnOffLocations();
			BlackFigure->SetActorHiddenInGame(true);
			BlackFigure->SetActorEnableCollision(false);
			BlackFigure->IsDead = true;
			moved = true;
			m_bCanAttack = false;
			WhiteKing->PossibleAttackDirections.Empty();
			WhiteKing->IsUnderAttack = false;
			WhiteKing->NumberOfMovesUnderAttack = 0;
			AttackKing();
			if (Material)
			{
				Mesh->SetMaterial(0, Material);
			}
		}
	}
}

bool AWhiteChief::CanMove(FVector Direction)
{	
	bool bIsValidMove = false;
	if (LineTrace(Direction))
	{
		FVector CurrentLocation = GetActorLocation();

		FVector Difference = Direction - CurrentLocation;

		bIsValidMove = (FMath::Abs(Difference.X) >= FMath::Abs(Difference.Y) - 500)
			&& (FMath::Abs(Difference.X) <= FMath::Abs(Difference.Y) + 500);
	}

	return bIsValidMove;
}

bool AWhiteChief::WillOpenChack()
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

AWhiteChief::AWhiteChief()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}
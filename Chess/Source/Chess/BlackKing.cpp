// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackKing.h"
#include "OnePeaceOfBoard.h"
#include "Components/PointLightComponent.h"
#include <Kismet/GameplayStatics.h>
#include "WhiteKing.h"
#include "WhiteChessFigure.h"
#include "BlackElephant.h"

bool  ABlackKing::LineTrace(FVector Direction)
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
		AWhiteChessFigure* WhiteFigure = Cast<AWhiteChessFigure>(OutHit.GetActor());
		ABlackChessFigure* BlackFigure = Cast<ABlackChessFigure>(OutHit.GetActor());

		if (BlackFigure)
		{
			SpaceIsFree = false;

			FVector CurrentLocation = GetActorLocation();

			FVector Difference = Direction - CurrentLocation;

			bool bIsValidMove = FMath::Abs(Difference.X) <= 1500 && FMath::Abs(Difference.Y) <= 1500;
			SpaceIsFree = false;

			if (bIsValidMove)
			{
				BlackFigure->IsSafe = true;
			}
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
					if (CanMove(Direction))
					{
						FVector Difference1 = BoardPiece->GetActorLocation() - WhiteFigure->GetActorLocation();
						bool bIsValidField = (FMath::Abs(Difference1.X) <= 200 and FMath::Abs(Difference1.Y) <= 200);
						if (bIsValidField)
						{
							BoardPiece->Light->SetLightColor(AttackColor);
							BoardPiece->Light->SetVisibility(true);
						}
					}
				}
			}
			SpaceIsFree = true;
		}
	}
	return SpaceIsFree;
}

void ABlackKing::Castle(FVector Direction)
{
	FVector Difference = Direction - GetActorLocation();
	if (FMath::Abs(Difference.Y) >= 1500 and FMath::Abs(Difference.Y) <= 2500)
	{
		FVector NewElehpantLocation(RightElephant->GetActorLocation().X, RightElephant->GetActorLocation().Y - 2000, RightElephant->GetActorLocation().Z);
		SetActorLocation(Direction);
		RightElephant->SetActorLocation(NewElehpantLocation);
	}
	else
	{
		FVector NewElehpantLocation(7804, 1930, RightElephant->GetActorLocation().Z);
		SetActorLocation(Direction);
		LeftElephant->SetActorLocation(NewElehpantLocation);
	}
}

bool ABlackKing::AttackUnderChack(AWhiteChessFigure* WhiteFigure)
{
	FVector AttackDirection = WhiteFigure->GetActorLocation();
	FVector Start = GetActorLocation();
	FVector End = AttackDirection;

	bool CanAttackUnderChack = false;

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

	if (WhiteFigureHit and WhiteFigure->GetName() == WhiteFigureHit->GetName())
	{
		WhiteFigureHit->IsSafe = false;
		for (AWhiteChessFigure* WhiteFigurik : WhiteFigures)
		{
			WhiteFigurik->LineTrace(WhiteFigure->GetActorLocation());
			if (WhiteFigure->IsSafe == true)
			{	
				break;
			}
		}
		if (WhiteFigure->IsSafe == false)
		{
			bCanAttack = true;
		}
		else
		{	
			bCanAttack = false;
		}
	}
	return bCanAttack;
}

void  ABlackKing::move(FVector Direction)
{
	if (UnderAttack(Direction) == false)
	{
		if (LineTrace(Direction))
		{
			FVector CurrentLocation = GetActorLocation();

			FVector Difference = Direction - CurrentLocation;

			FVector LeftElephantDirection = CurrentLocation - Direction;

			bool bIsValidMove = FMath::Abs(Difference.X) <= 1500 && FMath::Abs(Difference.Y) <= 1500;

			bool CanDoRacirovka = false;

			if (index == 0 and RightElephant->index == 0 and LeftElephant->index == 0)
			{
				CanDoRacirovka = FMath::Abs(Difference.X) <= 200 and ((Difference.Y >= 1200 and Difference.Y <= 2800)
					or (LeftElephantDirection.Y >= 2200 and LeftElephantDirection.Y <= 3800));
			}
			else if (index == 0 and RightElephant->index == 0 and LeftElephant->index != 0)
			{
				CanDoRacirovka = FMath::Abs(Difference.X) <= 200 and (Difference.X >= 1200 and Difference.Y <= 2800);
			}
			else if (index == 0 and LeftElephant->index == 0 and RightElephant->index != 0)
			{
				CanDoRacirovka = FMath::Abs(Difference.X) <= 200 and (LeftElephantDirection.Y >= 2200 and LeftElephantDirection.Y <= 3800);
			}

			if (CanDoRacirovka)
			{
				Castle(Direction);
				moved = true;
				IsUnderAttack = false;
				PossibleAttackDirections.Empty();
				NumberOfMovesUnderAttack = 0;
			}
			else if (bIsValidMove)
			{
				SetActorLocation(Direction);
				moved = true;
				IsUnderAttack = false;
				PossibleAttackDirections.Empty();
				NumberOfMovesUnderAttack = 0;
			}
		}

		if (Material)
		{
			Mesh->SetMaterial(0, Material);
		}

		if (moved == true)
		{
			NumberOfMovesUnderAttack = 0;
			++index;
		}
	}
}

void  ABlackKing::ShowLocations()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOnePeaceOfBoard::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		AOnePeaceOfBoard* BoardPiece = Cast<AOnePeaceOfBoard>(Actor);
		if (BoardPiece)
		{
			FVector CurrentLocation = GetActorLocation();

			FVector Direction = BoardPiece->GetActorLocation();

			FVector Difference = Direction - CurrentLocation;

			FVector LeftElephantDirection = CurrentLocation - Direction;

			if (LineTrace(FVector(Direction.X, Direction.Y, GetActorLocation().Z)))
			{
				bool bIsValidMove = FMath::Abs(Difference.X) <= 1500 && FMath::Abs(Difference.Y) <= 1500;

				bool CanDoRacirovka = false;

				if (index == 0 and RightElephant->index == 0 and LeftElephant->index == 0)
				{
					CanDoRacirovka = FMath::Abs(Difference.X) <= 200 and ((Difference.Y >= 1200 and Difference.Y <= 2800)
						or (LeftElephantDirection.Y >= 2200 and LeftElephantDirection.Y <= 3800));
				}
				else if (index == 0 and RightElephant->index == 0 and LeftElephant->index != 0)
				{
					CanDoRacirovka = FMath::Abs(Difference.X) <= 200 and (Difference.X >= 1200 and Difference.Y <= 2800);
				}
				else if (index == 0 and LeftElephant->index == 0 and RightElephant->index != 0)
				{
					CanDoRacirovka = FMath::Abs(Difference.X) <= 200 and (LeftElephantDirection.Y >= 2200 and LeftElephantDirection.Y <= 3800);
				}

				if (bIsValidMove or CanDoRacirovka)
				{
					if (UnderAttack(Direction) == false)
					{
						BoardPiece->Light->SetVisibility(true);
					}
				}
			}
		}
	}
}

void  ABlackKing::TurnOffLocations()
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

bool ABlackKing::CanAttack(FVector Direction)
{	
	if (LineTrace(Direction))
	{
		bool bIsValidMove = false;
		bool bbCanAttack = false;
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWhiteChessFigure::StaticClass(), FoundActors);
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

		if (bbCanAttack)
		{
			FVector CurrentLocation = GetActorLocation();
			FVector Difference = Direction - CurrentLocation;
			bIsValidMove = FMath::Abs(Difference.X) <= 1500 && FMath::Abs(Difference.Y) <= 1500;
		}

		return bIsValidMove;
	}
	else
	{
		return false;
	}
}

void ABlackKing::Attack(AWhiteChessFigure* WhiteFigure)
{
	FVector AttackDirection = WhiteFigure->GetActorLocation();
	
	if (AttackUnderChack(WhiteFigure))
	{
		SetActorLocation(FVector(AttackDirection.X, AttackDirection.Y, GetActorLocation().Z));
		TurnOffLocations();
		WhiteFigure->SetActorHiddenInGame(true);
		WhiteFigure->SetActorEnableCollision(false);
		WhiteFigure->IsDead = true;
		moved = true;
		IsUnderAttack = false;
		PossibleAttackDirections.Empty();
		NumberOfMovesUnderAttack = 0;
		if (Material)
		{
			Mesh->SetMaterial(0, Material);
		}
	}
}

bool ABlackKing::CanMove(FVector Direction)
{
	FVector CurrentLocation = GetActorLocation();

	FVector Difference = Direction - CurrentLocation;

	bool bIsValidMove = FMath::Abs(Difference.X) <= 1500 && FMath::Abs(Difference.Y) <= 1500;

	return bIsValidMove;
}

bool ABlackKing::UnderAttack(FVector Direction)
{
	bool UnderAttack = false;
	for (AWhiteChessFigure* WhiteFigure : WhiteFigures)
	{	
		FVector Difference = Direction - GetActorLocation();
		
		if (WhiteFigure->CanMove(Direction))
		{
			UnderAttack = true;
		}
	}

	return UnderAttack;
}

void ABlackKing::MoveUnderAttack()
{	
	if (IsUnderAttack)
	{
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOnePeaceOfBoard::StaticClass(), FoundActors);

		for (AActor* Actor : FoundActors)
		{
			AOnePeaceOfBoard* BoardPiece = Cast<AOnePeaceOfBoard>(Actor);
			if (BoardPiece)
			{
				FVector CurrentLocation = GetActorLocation();

				FVector Direction = BoardPiece->GetActorLocation();

				FVector Difference = Direction - CurrentLocation;

				if (LineTrace(FVector(Direction.X, Direction.Y, GetActorLocation().Z)))
				{	
					if (FMath::Abs(Difference.X) >= 900 and FMath::Abs(Difference.Y) >= 900)
					{
						bool bIsValidMove = FMath::Abs(Difference.X) <= 1500 && FMath::Abs(Difference.Y) <= 1500;

						if (bIsValidMove)
						{
							if (UnderAttack(Direction) == false)
							{	
								++NumberOfMovesUnderAttack;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		NumberOfMovesUnderAttack = 0;
	}
}

ABlackKing::ABlackKing()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}
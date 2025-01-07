// Fill out your copyright notice in the Description page of Project Settings.


#include "WhiteKing.h"
#include "OnePeaceOfBoard.h"
#include "Components/PointLightComponent.h"
#include <Kismet/GameplayStatics.h>
#include "BlackChessFigure.h"
#include "BlackKing.h"
#include "WhiteElephant.h"

bool AWhiteKing::AttackUnderChack(ABlackChessFigure* WhiteFigure)
{
	FVector AttackDirection = WhiteFigure->GetActorLocation();
	FVector Start = GetActorLocation();
	FVector End = AttackDirection;

	bool bCanAttack = false;

	bool CanAttackUnderChack = false;

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

	if (BlackFigureHit and WhiteFigure->GetName() == BlackFigureHit->GetName())
	{
		BlackFigureHit->IsSafe = false;
		for (ABlackChessFigure* BlackFigurik : BlackFigures)
		{
			BlackFigurik->LineTrace(WhiteFigure->GetActorLocation());
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

bool AWhiteKing::LineTrace(FVector Direction)
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

		if (WhiteFigure and WhiteFigure != this)
		{	
			FVector CurrentLocation = GetActorLocation();

			FVector Difference = Direction - CurrentLocation;

			bool bIsValidMove = FMath::Abs(Difference.X) <= 1500 && FMath::Abs(Difference.Y) <= 1500;
			SpaceIsFree = false;

			if (bIsValidMove)
			{
				WhiteFigure->IsSafe = true;
			}
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

					bool bIsValidMove = FMath::Abs(Difference.X) <= 1500 && FMath::Abs(Difference.Y) <= 1500;

					if (bIsValidMove)
					{
						FVector Difference1 = BoardPiece->GetActorLocation() - BlackFigure->GetActorLocation();
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

void AWhiteKing::Castle(FVector Direction)
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
		FVector NewElehpantLocation(804, 1930, RightElephant->GetActorLocation().Z);
		SetActorLocation(Direction);
		LeftElephant->SetActorLocation(NewElehpantLocation);
	}
}

void AWhiteKing::move(FVector Direction)
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
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
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

		if (moved)
		{
			++index;
		}
	}
}

void AWhiteKing::ShowLocations()
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

void AWhiteKing::TurnOffLocations()
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

bool AWhiteKing::CanAttack(FVector Direction)
{	
	if (UnderAttack(Direction) == false)
	{
		if (LineTrace(Direction))
		{
			bool bIsValidMove = false;
			bool bCanAttack = false;
			TArray<AActor*> FoundActors;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABlackChessFigure::StaticClass(), FoundActors);
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

			if (bCanAttack)
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
	else
	{
		return false;
	}
}

void AWhiteKing::Attack(ABlackChessFigure* BlackFigure)
{
	FVector AttackDirection = BlackFigure->GetActorLocation();

	if (AttackUnderChack(BlackFigure))
	{
		SetActorLocation(FVector(AttackDirection.X, AttackDirection.Y, GetActorLocation().Z));
		TurnOffLocations();
		BlackFigure->SetActorHiddenInGame(true);
		BlackFigure->SetActorEnableCollision(false);
		BlackFigure->IsDead = true;
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

bool AWhiteKing::UnderAttack(FVector Direction)
{	
	bool UnderAttack = false;
	for (ABlackChessFigure* BlackFigure : BlackFigures)
	{	
		if (BlackFigure->CanMove(Direction))
		{	
	 		UnderAttack = true;
		}
	}

	return UnderAttack;
}

bool AWhiteKing::CanMove(FVector Direction)
{
	FVector CurrentLocation = GetActorLocation();

	FVector Difference = Direction - CurrentLocation;

	bool bIsValidMove = FMath::Abs(Difference.X) <= 1500 && FMath::Abs(Difference.Y) <= 1500;

	return bIsValidMove;
}

AWhiteKing::AWhiteKing()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}

void AWhiteKing::MoveUnderAttack()
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
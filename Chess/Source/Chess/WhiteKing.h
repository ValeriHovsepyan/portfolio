// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WhiteChessFigure.h"
#include "WhiteKing.generated.h"

class ABlackChessFigure;
class AWhiteElephant;

/**
 * 
 */
UCLASS()
class CHESS_API AWhiteKing : public AWhiteChessFigure
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<ABlackChessFigure*> BlackFigures;

	int index = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AWhiteElephant> RightElephant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AWhiteElephant> LeftElephant;

	void Castle(FVector Direction);

public:
	bool AttackUnderChack(ABlackChessFigure* WhiteFigure);

	virtual bool LineTrace(FVector Direction) override;

	virtual void move(FVector Direction) override;

	virtual void ShowLocations() override;

	virtual void TurnOffLocations() override;

	virtual bool CanAttack(FVector Direction);

	virtual void Attack(ABlackChessFigure* BlackFigure);

	bool UnderAttack(FVector Direction);

	virtual bool CanMove(FVector Direction) override;

	AWhiteKing();

	virtual void MoveUnderAttack() override;

	int NumberOfMovesUnderAttack = 0;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<FVector> PossibleAttackDirections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool IsUnderAttack = false;
};

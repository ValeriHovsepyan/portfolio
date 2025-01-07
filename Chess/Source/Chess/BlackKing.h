// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlackChessFigure.h"
#include "BlackKing.generated.h"
class AWhiteChessFigure;
class ABlackElephant;
/**
 * 
 */
UCLASS()
class CHESS_API ABlackKing : public ABlackChessFigure
{
	GENERATED_BODY()
protected:
	virtual bool LineTrace(FVector Direction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<AWhiteChessFigure*> WhiteFigures;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<ABlackElephant> RightElephant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<ABlackElephant> LeftElephant;

	void Castle(FVector Direction);

	bool bCanAttack = false;

public:
	bool AttackUnderChack(AWhiteChessFigure* WhiteFigure);

	virtual void move(FVector Direction) override;

	virtual void ShowLocations() override;

	virtual void TurnOffLocations() override;

	virtual bool CanAttack(FVector Direction) override;

	virtual void Attack(AWhiteChessFigure* WhiteFigure) override;

	virtual bool CanMove(FVector Direction);

	bool UnderAttack(FVector Direction);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<FVector> PossibleAttackDirections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool IsUnderAttack = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int NumberOfMovesUnderAttack = 0;

	virtual void MoveUnderAttack() override;

	int index = 0;

	ABlackKing();
};

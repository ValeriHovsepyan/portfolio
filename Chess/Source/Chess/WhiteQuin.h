// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WhiteChessFigure.h"
#include "WhiteQuin.generated.h"

class ABlackChessFigure;
class AWhiteKing;

/**
 * 
 */
UCLASS()
class CHESS_API AWhiteQuin : public AWhiteChessFigure
{
	GENERATED_BODY()
protected:

	bool bCanAttack = false;

	bool m_CanAttackKing = false;

public:
	virtual void ShowLocations() override;

	virtual bool LineTrace(FVector Direction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AWhiteKing> WhiteKing;

	virtual void TurnOffLocations() override;

	virtual void move(FVector Direction) override;

	virtual bool CanAttack(FVector Direction);

	virtual void Attack(ABlackChessFigure* BlackFigure);

	virtual bool CanMove(FVector Direction) override;

	UFUNCTION(BlueprintCallable)
	bool WillOpenChack();

	virtual void AttackKing() override;

	virtual void MoveUnderAttack() override;

	AWhiteQuin();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WhiteChessFigure.h"
#include "WhiteElephant.generated.h"

class ABlackChessFigure;
class AWhiteKing;
/**
 * 
 */
UCLASS()
class CHESS_API AWhiteElephant : public AWhiteChessFigure
{
	GENERATED_BODY()
protected:
	bool m_bCanAttack = false;

	bool m_CanAttackKing = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AWhiteKing> WhiteKing;

public:
	virtual bool LineTrace(FVector Direction) override;

	virtual void move(FVector Direction) override;

	virtual void ShowLocations() override;

	virtual void TurnOffLocations() override;

	virtual bool CanAttack(FVector Direction);

	virtual void Attack(ABlackChessFigure* BlackFigure);

	virtual bool CanMove(FVector Direction) override;

	int index = 0;

	UFUNCTION(BlueprintCallable)
	bool WillOpenChack();

	virtual void AttackKing() override;

	virtual void MoveUnderAttack() override;

	AWhiteElephant();
};

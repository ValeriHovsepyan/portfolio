// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlackChessFigure.h"
#include "BlackQuin.generated.h"

class ABlackKing;
class AWhiteChessFigure;
/**
 * 
 */
UCLASS()
class CHESS_API ABlackQuin : public ABlackChessFigure
{
	GENERATED_BODY()
protected:
	virtual bool LineTrace(FVector Direction) override;

	bool m_bCanAttack = false;

	bool m_CanAttackKing = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<ABlackKing> BlackKing;

public:
	virtual void ShowLocations() override;

	virtual void TurnOffLocations() override;

	virtual void move(FVector Direction) override;

	virtual bool CanAttack(FVector Direction) override;

	virtual void Attack(AWhiteChessFigure* WhiteFigure) override;

	virtual bool CanMove(FVector Direction);

	virtual void AttackKing() override;

	UFUNCTION(BlueprintCallable)
	bool WillOpenChack();

	virtual void MoveUnderAttack() override;

	ABlackQuin();
};

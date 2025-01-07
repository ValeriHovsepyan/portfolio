// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlackChessFigure.h"
#include "BlackKnight.generated.h"

class AWhiteChessFigure;
class ABlackKing;

/**
 * 
 */
UCLASS()
class CHESS_API ABlackKnight : public ABlackChessFigure
{
	GENERATED_BODY()

	bool m_bCanAttack = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<ABlackKing> BlackKing;
public:
	virtual void move(FVector Direction) override;

	virtual void ShowLocations() override;

	virtual void TurnOffLocations() override;

	virtual bool CanAttack(FVector Direction) override;

	virtual void Attack(AWhiteChessFigure* WhiteFigure) override;

	virtual bool CanMove(FVector Direction);

	virtual void AttackKing();

	UFUNCTION(BlueprintCallable)
	bool WillOpenChack();

	virtual bool LineTrace(FVector Direction) override;

	virtual void MoveUnderAttack() override;

	ABlackKnight();
};

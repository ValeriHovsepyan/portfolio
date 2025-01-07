// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WhiteChessFigure.h"
#include "WhiteKnight.generated.h"

class ABlackChessFigure;
class AWhiteKing;

/**
 * 
 */
UCLASS()
class CHESS_API AWhiteKnight : public AWhiteChessFigure
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AWhiteKing> WhiteKing;
public:
	virtual void move(FVector Direction) override;

	virtual void ShowLocations() override;

	virtual void TurnOffLocations() override;

	virtual bool CanAttack(FVector Direction);

	virtual void Attack(ABlackChessFigure* BlackFigure);
	
	virtual bool CanMove(FVector Direction) override;

	virtual void AttackKing() override;

	virtual bool LineTrace(FVector Direction) override;

	UFUNCTION(BlueprintCallable)
	bool WillOpenChack();

	virtual void MoveUnderAttack() override;

	AWhiteKnight();
};

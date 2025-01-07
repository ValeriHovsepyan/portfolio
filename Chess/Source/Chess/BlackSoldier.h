 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlackChessFigure.h"
#include "BlackSoldier.generated.h"

class AWhiteChessFigure;
class ABlackKing;

/**
 * 
 */
UCLASS()
class CHESS_API ABlackSoldier : public ABlackChessFigure
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int index = 0;

	virtual void ShowLocations() override;

	virtual void TurnOffLocations() override;

	virtual bool LineTrace(FVector Direction) override;

	bool m_bCanAttack = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<ABlackKing> BlackKing;

public:
	virtual void move(FVector Direction) override;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<class UBlackSoldierChangeFigure> ChangeSoldierRef = nullptr;

	virtual bool CanAttack(FVector Direction) override;

	virtual void Attack(AWhiteChessFigure* WhiteFigure) override;

	virtual bool CanMove(FVector Direction);

	UFUNCTION(BlueprintCallable)
	bool WillOpenChack();

	virtual void AttackKing() override;

	virtual void MoveUnderAttack() override;

	ABlackSoldier();
};

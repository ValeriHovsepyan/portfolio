// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WhiteChessFigure.h"
#include "whiteSoldier.generated.h"

class ABlackChessFigure;
class AWhiteKing;

/**
 * 
 */
UCLASS()
class CHESS_API AwhiteSoldier : public AWhiteChessFigure
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int index = 0;

	virtual void ShowLocations() override;

	virtual void TurnOffLocations() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AWhiteKing> WhiteKing;

	bool m_bCanAttack = false;
public:
	virtual void move(FVector Direction) override;

	virtual bool LineTrace(FVector Direction) override;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<class UChangeFidureWidget> ChangeSoldierRef = nullptr;

	AwhiteSoldier();

	virtual bool CanAttack(FVector Direction) override;

	virtual void Attack(ABlackChessFigure* BlackFigure) override;

	UFUNCTION(BlueprintCallable)
	bool WillOpenChack();

	virtual void MoveUnderAttack() override;

	virtual void AttackKing() override;

	virtual bool CanMove(FVector Direction) override;
};

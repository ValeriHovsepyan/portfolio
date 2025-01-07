// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BlackSoldierChangeFigure.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API UBlackSoldierChangeFigure : public UUserWidget
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class ABlackSoldier* Soldier;
public:
	void SetSoldier(ABlackSoldier* Sold);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChangeFidureWidget.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API UChangeFidureWidget : public UUserWidget
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class AwhiteSoldier* Soldier;
public:
	void SetSoldier(AwhiteSoldier* Sold);
};

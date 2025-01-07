// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Food.h"
#include "SuperFood.generated.h"

/**
 * 
 */
UCLASS()
class SNAKE_API ASuperFood : public AFood
{
	GENERATED_BODY()

public:
	ASuperFood();

	virtual void Spawn() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};

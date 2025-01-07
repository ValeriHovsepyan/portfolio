// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WhiteChessFigure.generated.h"

class ABlackChessFigure;

UCLASS()
class CHESS_API AWhiteChessFigure : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UStaticMeshComponent> Mesh = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInterface* Material;
public:	
	// Sets default values for this actor's properties
	AWhiteChessFigure();

	virtual void AttackKing();

	bool IsSafe = false;

	virtual bool LineTrace(FVector Direction);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void ShowLocations();

	UFUNCTION(BlueprintCallable)
	virtual void TurnOffLocations();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FColor AttackColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FColor UsualColor;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void move(FVector Direction);

	UFUNCTION(BlueprintCallable)
	virtual UStaticMeshComponent* GetMesh();

	virtual void MoveUnderAttack();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool moved = false;

	UFUNCTION(BlueprintCallable)
	virtual bool CanAttack(FVector Direction);

	UFUNCTION(BlueprintCallable)
	virtual void Attack(ABlackChessFigure* BlackFigure);

	virtual bool CanMove(FVector Direction);

	bool IsDead = false;
};

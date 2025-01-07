// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlackChessFigure.generated.h"

class AWhiteChessFigure;

UCLASS()
class CHESS_API ABlackChessFigure : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlackChessFigure();
	
	bool IsSafe = false;

	virtual bool LineTrace(FVector Direction);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UStaticMeshComponent> Mesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInterface* Material;

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

	virtual bool CanMove(FVector Direction);

	UFUNCTION(BlueprintCallable)
	virtual UStaticMeshComponent* GetMesh();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool moved = false;

	bool IsDead = false;

	UFUNCTION(BlueprintCallable)
	virtual bool CanAttack(FVector Direction);

	UFUNCTION(BlueprintCallable)
	virtual void Attack(AWhiteChessFigure* BlackFigure);

	virtual void AttackKing();

	virtual void MoveUnderAttack();
};

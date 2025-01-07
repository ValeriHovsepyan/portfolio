// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeBody.h"
#include "Components/BoxComponent.h"
#include "SnakeCharacter.h"
#include <Kismet/GameplayStatics.h>

ASnakeBody::ASnakeBody()
{
	Body = CreateDefaultSubobject<UStaticMeshComponent>("body");
	SetRootComponent(Body);

	Collision = CreateDefaultSubobject<UBoxComponent>("Collision");
	Collision->SetupAttachment(Body);

	Collision->OnComponentBeginOverlap.AddDynamic(this, &ASnakeBody::OnOverlapBegin);
}

void ASnakeBody::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ASnakeCharacter* Character = Cast<ASnakeCharacter>(OtherActor);
	if (Character)
	{
		Character->Score = 0;
		UGameplayStatics::OpenLevel(GetWorld(), Character->LoserLevel, true);
	}
}

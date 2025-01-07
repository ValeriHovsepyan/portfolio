// Copyright Epic Games, Inc. All Rights Reserved.

#include "SnakeCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Food.h"
#include "SnakeBody.h"
#include "SuperFood.h"
#include "Components/SplineMeshComponent.h"
#include <Kismet/GameplayStatics.h>

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ASnakeCharacter

ASnakeCharacter::ASnakeCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	location = CreateDefaultSubobject<UStaticMeshComponent>("Location");
	location->SetupAttachment(Mesh);

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ASnakeCharacter::OnOverlapBegin);

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void ASnakeCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	SpawnBody(1);
}

void ASnakeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetVelocity().Length() > 10)
	{
		UpdateBodyLocation();
		UpdateSplineLocation();
	}
}

void ASnakeCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	Food = Cast<AFood>(OtherActor);
	if (Food)
	{	
		NumberOfBodies = Food->GetScore() / 10;
		Score += Food->GetScore();
		if (Score >= 280)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, WinnerLevel.ToString());
			UGameplayStatics::OpenLevel(GetWorld(), WinnerLevel, true);
			return;
		}
		Food->Spawn();
		Food->Destroy();
		SpawnBody(NumberOfBodies);
	}
}

void ASnakeCharacter::SpawnBody(int fnumberOfBodies)
{
	for (size_t i = 0; i < fnumberOfBodies; i++)
	{	
		FVector BodyLocation = location->GetComponentLocation() - GetActorForwardVector() * SpawnLocation;
		FRotator BodyRotation = GetActorRotation();

		FActorSpawnParameters SpawnParams;

		ASnakeBody* body = GetWorld()->SpawnActor<ASnakeBody>(SnakeBody, BodyLocation, BodyRotation, SpawnParams);

		body->SetActorHiddenInGame(true);

		SnakeBodyArray.Add(body);

		++BodyCount;

	}
	SetSplineScale();
}

void ASnakeCharacter::UpdateBodyLocation()
{
	if (SnakeBodyArray.Num() > 0)
	{
		BodyLocationArray.Empty();
		for (ASnakeBody* Body : SnakeBodyArray)
		{
			BodyLocationArray.Add(Body->GetActorTransform());
		}
		FTransform HeadTransform(location->GetComponentRotation(), location->GetComponentLocation(), BodyLocationArray[0].GetScale3D());
		SnakeBodyArray[0]->SetActorTransform(HeadTransform);
		int index = 0;
		float LerpAlpha = 0.05;
		for (FTransform BodyLocation : BodyLocationArray)
		{	
			if (index + 1 < BodyLocationArray.Num())
			{
				FTransform CurrentTransform = SnakeBodyArray[index + 1]->GetActorTransform();

				FVector LerpedTranslation = FMath::Lerp(CurrentTransform.GetTranslation(), BodyLocation.GetTranslation(), LerpAlpha);

				FQuat LerpedRotation = FQuat::Slerp(CurrentTransform.GetRotation(), BodyLocation.GetRotation(), LerpAlpha);

				FTransform NewBodyLocation(LerpedRotation, LerpedTranslation, SnakeBodyArray[index]->GetActorScale());

				SnakeBodyArray[index + 1]->SetActorTransform(NewBodyLocation);
				++index;
			}
		}
	}
}

void ASnakeCharacter::UpdateSplineLocation()
{	
	int index = 0;
	for (USplineMeshComponent* Spline : SnakeSplineArray)
	{
		if (index + 1 < SnakeBodyArray.Num())
		{
			FVector StartPos = SnakeBodyArray[index + 1]->GetActorLocation();
			FVector EndPos = SnakeBodyArray[index]->GetActorLocation();

			FVector Direction = (EndPos - StartPos).GetSafeNormal();

			FVector StartTangent = Direction;
			FVector EndTangent = -Direction * FVector(200, 200, 1);

			Spline->SetStartPosition(StartPos);
			Spline->SetStartTangent(StartTangent);
			Spline->SetEndPosition(EndPos);
			Spline->SetEndTangent(EndTangent);

			++index;
		}
	}
}

void ASnakeCharacter::SetSplineScale()
{
	int index = 0;
	for (USplineMeshComponent* Spline : SnakeSplineArray)
	{
		if (index + 1 < SnakeBodyArray.Num())
		{
			float StartSize = float((1.f - 0.03 * index));
			StartSize = FMath::Clamp(StartSize, 0.09f, 1.0f);

			float EndSize = float((1.f - 0.03 * (index + 1)));
			EndSize = FMath::Clamp(EndSize, 0.09f, 1.0f);

			FVector2D StartScale(StartSize, StartSize);
			FVector2D EndScale(EndSize, EndSize);

			Spline->SetStartScale(StartScale);
			Spline->SetEndScale(EndScale);

			++index;
		}
	}
}

int ASnakeCharacter::GetBodyCount()
{
	return BodyCount;
}

//////////////////////////////////////////////////////////////////////////
// Input

void ASnakeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) 
	{
		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASnakeCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASnakeCharacter::Look);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ASnakeCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ASnakeCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}
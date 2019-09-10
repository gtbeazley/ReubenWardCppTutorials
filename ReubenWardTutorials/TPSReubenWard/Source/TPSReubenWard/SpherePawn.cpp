// Fill out your copyright notice in the Description page of Project Settings.

#include "SpherePawn.h"

#include "Classes/GameFramework/FloatingPawnMovement.h" 
#include "Classes/GameFramework/SpringArmComponent.h"
#include "Classes/Camera/CameraComponent.h"
#include "Classes/Components/InputComponent.h"
#include "Classes/Components/StaticMeshComponent.h"

// Sets default values
ASpherePawn::ASpherePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");


	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	
	CameraArm = CreateDefaultSubobject<USpringArmComponent>("CameraSpringArm");
	CameraArm->SetupAttachment(StaticMesh);
	CameraArm->TargetArmLength = 500.0f;
	Camera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	Camera->SetupAttachment(CameraArm);

	SetRootComponent(StaticMesh);

	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = true;
}

// Called when the game starts or when spawned
void ASpherePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpherePawn::MoveForward(float a_val)
{
	FloatingPawnMovement->AddInputVector(GetActorForwardVector() * a_val);
}

void ASpherePawn::MoveRight(float a_val)
{
	FloatingPawnMovement->AddInputVector(GetActorRightVector() * a_val);
}

void ASpherePawn::Turn(float a_val)
{
	AddControllerYawInput(a_val);
}

void ASpherePawn::LookUp(float a_val)
{
	AddControllerPitchInput(a_val);
}

// Called every frame
void ASpherePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpherePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASpherePawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASpherePawn::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ASpherePawn::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ASpherePawn::LookUp);
}


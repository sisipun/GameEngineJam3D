// Fill out your copyright notice in the Description page of Project Settings.

#include "Hero.h"

// Sets default values
AHero::AHero()
{
    AutoPossessPlayer = EAutoReceiveInput::Player0;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMesh(TEXT("/Game/Meshes/BallMesh.BallMesh"));

    Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Ball->SetStaticMesh(BallMesh.Object);
	Ball->BodyInstance.SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
	Ball->SetSimulatePhysics(true);
	Ball->SetAngularDamping(0.1f);
	Ball->SetLinearDamping(0.1f);
	Ball->BodyInstance.MassScale = 3.5f;
	Ball->BodyInstance.MaxAngularVelocity = 800.0f;
	Ball->SetNotifyRigidBodyCollision(true);
	RootComponent = Ball;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bAbsoluteRotation = true;
	SpringArm->RelativeRotation = FRotator(-45.f, 0.f, 0.f);
	SpringArm->TargetArmLength = 1200.f;
	SpringArm->bEnableCameraLag = false;
	SpringArm->CameraLagSpeed = 3.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

    RollTorque = 10000000.0f;
}

void AHero::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveX", this, &AHero::MoveXAxis);
    PlayerInputComponent->BindAxis("MoveY", this, &AHero::MoveYAxis);
}

void AHero::MoveXAxis(float AxisValue)
{
    const FVector Torque = FVector(0.f, AxisValue * RollTorque, 0.f);
    Ball->AddTorqueInRadians(Torque);
}

void AHero::MoveYAxis(float AxisValue)
{
    const FVector Torque = FVector(-1.f * AxisValue * RollTorque, 0.f, 0.f);
    Ball->AddTorqueInRadians(Torque);
}

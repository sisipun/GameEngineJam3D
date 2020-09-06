// Fill out your copyright notice in the Description page of Project Settings.

#include "Hero.h"

AHero::AHero()
{
    AutoPossessPlayer = EAutoReceiveInput::Player0;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> HeroMesh(TEXT("/Game/Meshes/HeroMesh.HeroMesh"));

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
    Mesh->SetStaticMesh(HeroMesh.Object);
    Mesh->BodyInstance.SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
    Mesh->SetSimulatePhysics(true);
    Mesh->SetAngularDamping(0.1f);
    Mesh->SetLinearDamping(0.1f);
    Mesh->BodyInstance.MassScale = 3.5f;
    Mesh->BodyInstance.MaxAngularVelocity = 800.0f;
    Mesh->SetNotifyRigidBodyCollision(true);
    RootComponent = Mesh;

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
    JumpImpulse = 300000.0f;
    Score = 0;
    Dead = false;
    CanJump = true;
}

void AHero::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("Score: %d"), Score);
}

void AHero::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveX", this, &AHero::MoveXAxis);
    PlayerInputComponent->BindAxis("MoveY", this, &AHero::MoveYAxis);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AHero::Jump);
}

void AHero::MoveXAxis(float AxisValue)
{
    if (!Dead)
    {
        const FVector Torque = FVector(0.f, AxisValue * RollTorque, 0.f);
        Mesh->AddTorqueInRadians(Torque);
    }
}

void AHero::Jump()
{
    if (!Dead && CanJump)
    {
        const FVector Impulse = FVector(0.f, 0.f, JumpImpulse);
        Mesh->AddImpulse(Impulse);
        CanJump = false;
    }
}

void AHero::MoveYAxis(float AxisValue)
{
    if (!Dead)
    {
        const FVector Torque = FVector(-1.f * AxisValue * RollTorque, 0.f, 0.f);
        Mesh->AddTorqueInRadians(Torque);
    }
}

void AHero::NotifyHit(class UPrimitiveComponent *MyComp, class AActor *Other, class UPrimitiveComponent *OtherComp,
                      bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse,
                      const FHitResult &Hit)
{
    Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

    if (Other->GetName().Contains("Ground"))
    {
        CanJump = true;
    }
    else if (Other->GetName().Contains("Bonus"))
    {
        Score++;
        UE_LOG(LogTemp, Warning, TEXT("Score: %d"), Score);
    }
    else if (Other->GetName().Contains("Enemy"))
    {
        Dead = true;
        UE_LOG(LogTemp, Warning, TEXT("Game over"));
    }
}

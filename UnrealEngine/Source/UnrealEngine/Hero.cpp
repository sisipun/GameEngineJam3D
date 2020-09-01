// Fill out your copyright notice in the Description page of Project Settings.

#include "Hero.h"
#include "Camera/CameraComponent.h"

// Sets default values
AHero::AHero()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Set this pawn to be controlled by the lowest-numbered player
    AutoPossessPlayer = EAutoReceiveInput::Player0;

    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    VisualMesh->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(
        TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));

    if (CubeVisualAsset.Succeeded())
    {
        VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
        VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
        VisualMesh->SetSimulatePhysics(true);
    }

    UCameraComponent *OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
    OurCamera->SetupAttachment(VisualMesh);
    OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
    OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
}

// Called when the game starts or when spawned
void AHero::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AHero::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!CurrentVelocity.IsZero())
    {
        FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
        SetActorLocation(NewLocation);
    }
}

void AHero::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveX", this, &AHero::MoveXAxis);
    PlayerInputComponent->BindAxis("MoveY", this, &AHero::MoveYAxis);
}

void AHero::MoveXAxis(float AxisValue)
{
    CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 300.0f;
}

void AHero::MoveYAxis(float AxisValue)
{
    CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 300.0f;
}

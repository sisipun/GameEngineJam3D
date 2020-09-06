// Fill out your copyright notice in the Description page of Project Settings.

#include "Bonus.h"

ABonus::ABonus()
{
    PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> BonusMesh(TEXT("/Game/Meshes/BonusMesh.BonusMesh"));

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
    Mesh->SetStaticMesh(BonusMesh.Object);
    Mesh->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(30.0f, 45.0f, 90.0f));
    Mesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
    Mesh->SetNotifyRigidBodyCollision(true);
    Mesh->SetupAttachment(RootComponent);
}

void ABonus::NotifyHit(class UPrimitiveComponent *MyComp, class AActor *Other, class UPrimitiveComponent *OtherComp,
                       bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse,
                       const FHitResult &Hit)
{
    Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

    if (Other->GetName().Contains("Hero"))
    {
        Destroy();
    }
}

void ABonus::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector NewLocation = GetActorLocation();
    FRotator NewRotation = GetActorRotation();
    float RunningTime = GetGameTimeSinceCreation();
    float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
    NewLocation.Z += DeltaHeight * 20.0f;
    float DeltaRotation = DeltaTime * 20.0f;
    NewRotation.Yaw += DeltaRotation;
    SetActorLocationAndRotation(NewLocation, NewRotation);
}

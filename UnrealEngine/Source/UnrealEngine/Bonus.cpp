// Fill out your copyright notice in the Description page of Project Settings.

#include "Bonus.h"

ABonus::ABonus()
{
    PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/Meshes/CubeMesh.CubeMesh"));

    Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
    Cube->SetupAttachment(RootComponent);
    Cube->SetStaticMesh(CubeVisualAsset.Object);
    Cube->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(30.0f, 45.0f, 90.0f));
	Cube->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	Cube->SetNotifyRigidBodyCollision(true);
}

void ABonus::NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	Destroy();
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

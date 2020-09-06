// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemyMesh(TEXT("/Game/Meshes/EnemyMesh.EnemyMesh"));

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
    Mesh->SetStaticMesh(EnemyMesh.Object);
    Mesh->SetSimulatePhysics(true);
    Mesh->SetAngularDamping(0.1f);
    Mesh->SetLinearDamping(0.1f);
    Mesh->BodyInstance.MassScale = 3.5f;
    Mesh->BodyInstance.MaxAngularVelocity = 800.0f;
    Mesh->SetNotifyRigidBodyCollision(true);
    Mesh->SetupAttachment(RootComponent);

    RollTorque = 10000000.0f;
    MoveX = 1;
    MoveY = 0;
}

void AEnemy::NotifyHit(class UPrimitiveComponent *MyComp, class AActor *Other, class UPrimitiveComponent *OtherComp,
                       bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse,
                       const FHitResult &Hit)
{
    Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

    if (Other->GetName() != LastCollider && !Other->GetName().Contains("Ground"))
    {
        LastCollider = Other->GetName();
        MoveX *= -1;
        MoveY *= -1;
        UE_LOG(LogTemp, Warning, TEXT("Change"));
    }
}

void AEnemy::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    const FVector Torque = FVector(MoveY * DeltaTime * RollTorque, MoveX * DeltaTime * RollTorque, 0.f);
    Mesh->AddTorqueInRadians(Torque);
}

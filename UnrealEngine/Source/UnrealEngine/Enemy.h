// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class UNREALENGINE_API AEnemy : public AActor
{
    GENERATED_BODY()

  public:
    // Sets default values for this actor's properties
    AEnemy();

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent *Mesh;

    virtual void NotifyHit(class UPrimitiveComponent *MyComp, class AActor *Other, class UPrimitiveComponent *OtherComp,
                           bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse,
                           const FHitResult &Hit) override;

    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere)
    float RollTorque;

    UPROPERTY(EditAnywhere)
    int MoveX;

    UPROPERTY(EditAnywhere)
    int MoveY;

	FString LastCollider;
};

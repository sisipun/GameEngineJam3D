// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bonus.generated.h"

UCLASS()
class UNREALENGINE_API ABonus : public AActor
{
    GENERATED_BODY()

  public:
    ABonus();

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent *Cube;

    virtual void Tick(float DeltaTime) override;

    virtual void NotifyHit(class UPrimitiveComponent *MyComp, class AActor *Other, class UPrimitiveComponent *OtherComp,
                           bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse,
                           const FHitResult &Hit) override;
};

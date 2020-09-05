// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "Engine/CollisionProfile.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Hero.generated.h"

UCLASS()
class UNREALENGINE_API AHero : public APawn
{
    GENERATED_BODY()

  public:
    AHero();

    virtual void BeginPlay() override;

    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

    virtual void NotifyHit(class UPrimitiveComponent *MyComp, class AActor *Other, class UPrimitiveComponent *OtherComp,
                           bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse,
                           const FHitResult &Hit) override;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent *Ball;

    UPROPERTY(VisibleAnywhere)
    USpringArmComponent *SpringArm;

    UPROPERTY(VisibleAnywhere)
    UCameraComponent *Camera;

    void MoveXAxis(float AxisValue);
    void MoveYAxis(float AxisValue);

    UPROPERTY(EditAnywhere)
    float RollTorque;

    int Score;
};

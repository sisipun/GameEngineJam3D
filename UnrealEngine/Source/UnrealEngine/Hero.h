// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Hero.generated.h"


UCLASS()
class UNREALENGINE_API AHero : public APawn
{
    GENERATED_BODY()

  public:
    // Sets default values for this pawn's properties
    AHero();

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

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
};

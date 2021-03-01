// Copyright (C) Rapyuta Robotics

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/FloatingPawnMovement.h"

#include "TurtlebotMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class TURTLEBOT3_API UTurtlebotMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(Transient)
	FVector DesiredMovement;

	UPROPERTY(Transient)
	FQuat DesiredRotation;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Velocity)
	FVector AngularVelocity;

private:

	virtual void UpdateMovement(float DeltaTime);

public:

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
};

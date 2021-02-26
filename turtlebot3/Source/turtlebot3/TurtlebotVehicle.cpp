// Copyright (C) Rapyuta Robotics


#include "TurtlebotVehicle.h"
#include "TurtlebotMovementComponent.h"

#include "ROS2Node.h"
#include "Msgs/ROS2TFMsg.h"

ATurtlebotVehicle::ATurtlebotVehicle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UTurtlebotMovementComponent>(VehicleMovementComponentName))
{
}


void ATurtlebotVehicle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


void ATurtlebotVehicle::SetLinearVel(FVector Velocity)
{
	// We're assuming input is in meters, so convert to centimeters.
	GetVehicleMovementComponent()->Velocity = Velocity * 100.0f;
}


void ATurtlebotVehicle::SetAngularVel(FVector Velocity)
{
	UTurtlebotMovementComponent *TurtlebotMovementComponent = Cast<UTurtlebotMovementComponent>(GetVehicleMovementComponent());

	if (TurtlebotMovementComponent)
	{
		TurtlebotMovementComponent->AngularVelocity = Velocity;
	}
}


void ATurtlebotVehicle::BeginPlay()
{
	Super::BeginPlay();

/*
	for (TFieldIterator<FProperty> PropIt(FTestData::StaticStruct()); PropIt; ++PropIt)
	{
		FProperty *Property = *PropIt;
		
		FString Name = Property->GetName();
		FString Type = Property->GetCPPType();

		UE_LOG(LogTemp, Warning, TEXT("*** Prop: %s (%s)"), *Name, *Type);
	}
*/
}


void ATurtlebotVehicle::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

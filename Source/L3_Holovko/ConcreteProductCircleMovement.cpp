// Fill out your copyright notice in the Description page of Project Settings.


#include "ConcreteProductCircleMovement.h"

void AConcreteProductCircleMovement::DrawMovementLines(double LinesLifeTime)
{
	const double StartRadius = Radius;
	Super::DrawMovementLines(LinesLifeTime);
	Radius = StartRadius;
}

void AConcreteProductCircleMovement::ResetStartSettings()
{
	CalculateMovementDirection();
	StartMovingDirectionZ = MovementDirectionVector.Z;
	EndMovementPoint.X = StartMovementPoint.X;
	EndMovementPoint.Y = StartMovementPoint.Y;
}

void AConcreteProductCircleMovement::Move(float DeltaTime, const double& TimeSinceCreation)
{
	MoveStraight(DeltaTime);
	if (IsHeightAlignedToEndPoint())
	{
		CalculateMovementDirection();
		Radius -= 100 * DeltaTime;
	}
	CalculateRadialMovement(TimeSinceCreation);
}

void AConcreteProductCircleMovement::CalculateRadialMovement(const double& TimeSinceCreation)
{
	FVector NewLocation = StaticMesh->GetRelativeLocation();
	NewLocation.X = StartMovementPoint.X + Radius * FMath::Cos(RotationPeriod * TimeSinceCreation);
	NewLocation.Y = StartMovementPoint.Y + Radius * FMath::Sin(RotationPeriod * TimeSinceCreation);

	SetActorLocation(NewLocation);
}

bool AConcreteProductCircleMovement::IsHeightAlignedToEndPoint() const
{
	if (StartMovingDirectionZ >= 0)
	{
		return GetActorLocation().Z >= EndMovementPoint.Z;
	}
	else
	{
		return GetActorLocation().Z <= EndMovementPoint.Z;
	}
}

void AConcreteProductCircleMovement::SetStartSettings(FVector StartPoint, FVector EndPoint, double MovSpeed, bool bShouldBeDestroyed, double RotationRadius, double CircleRotationPeriod)
{
	Radius = RotationRadius;
	RotationPeriod = CircleRotationPeriod;
	SetBaseStartSettings(StartPoint, EndPoint, MovSpeed, bShouldBeDestroyed);
}

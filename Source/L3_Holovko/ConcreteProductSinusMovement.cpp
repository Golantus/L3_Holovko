// Fill out your copyright notice in the Description page of Project Settings.


#include "ConcreteProductSinusMovement.h"

void AConcreteProductSinusMovement::ResetStartSettings()
{
	CalculateMovementDirection();
	NonWobblingLocation = StartMovementPoint;
	MaxDistanceToMove = FVector::Dist(
		StartMovementPoint, EndMovementPoint
	);
}

void AConcreteProductSinusMovement::Move(float DeltaTime, const double& TimeSinceCreation)
{
	MoveStraight(DeltaTime);
	CalculateMovementDirection();
	NonWobblingLocation += MovementDirectionVector * MovementSpeed * DeltaTime;
	Wobble(TimeSinceCreation);
}

void AConcreteProductSinusMovement::Wobble(const double& TimeSinceCreation)
{
	FVector WobbleLocation = GetActorLocation();
	if (Frequency.X && MaxWobbleDistance.X)
	{
		WobbleLocation.X = CalculateWobbleLocation(Frequency.X, NonWobblingLocation.X, MaxWobbleDistance.X, TimeSinceCreation);
	}
	if (Frequency.Y && MaxWobbleDistance.Y)
	{
		WobbleLocation.Y = CalculateWobbleLocation(Frequency.Y, NonWobblingLocation.Y, MaxWobbleDistance.Y, TimeSinceCreation);
	}
	if (Frequency.Z && MaxWobbleDistance.Z)
	{
		WobbleLocation.Z = CalculateWobbleLocation(Frequency.Z, NonWobblingLocation.Z, MaxWobbleDistance.Z, TimeSinceCreation);
	}
	SetActorLocation(WobbleLocation);
}

double AConcreteProductSinusMovement::CalculateWobbleLocation(const double& Freq, const double& NonWobbleLocation, const double& MaxWobbleDist, const double& TimeSinceCreation) const
{
	double wt = Freq * TWO_PI * TimeSinceCreation;
	double phase = (MaxDistanceToMove / Freq) / TWO_PI;
	return NonWobbleLocation + MaxWobbleDist * FMath::Sin(wt + phase);
}

void AConcreteProductSinusMovement::SetStartSettings(FVector StartPoint, FVector EndPoint, double MovSpeed, bool bShouldBeDestroyed, FVector Freq, FVector MaxWobbleDist)
{
	Frequency = Freq;
	MaxWobbleDistance = MaxWobbleDist;
	SetBaseStartSettings(StartPoint, EndPoint, MovSpeed, bShouldBeDestroyed);
}

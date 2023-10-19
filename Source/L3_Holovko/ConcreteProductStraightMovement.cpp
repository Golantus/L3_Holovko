// Fill out your copyright notice in the Description page of Project Settings.


#include "ConcreteProductStraightMovement.h"
#include "Components/LineBatchComponent.h"

void AConcreteProductStraightMovement::DrawMovementLines(double LinesLifeTime)
{
	LineBatch->DrawLine(StartMovementPoint, EndMovementPoint, FColor::Red, 10.f, 3.f, LinesLifeTime);
}

void AConcreteProductStraightMovement::ResetStartSettings()
{
	SetActorLocation(StartMovementPoint);
	CalculateMovementDirection();
}

void AConcreteProductStraightMovement::Move(float DeltaTime, const double& TimeSinceCreation)
{
	MoveStraight(DeltaTime);
}

void AConcreteProductStraightMovement::SetStartSettings(FVector StartPoint, FVector EndPoint, double MovSpeed, bool bShouldBeDestroyed)
{
	SetBaseStartSettings(StartPoint, EndPoint, MovSpeed, bShouldBeDestroyed);
	ResetStartSettings();
}
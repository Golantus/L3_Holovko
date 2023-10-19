// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Product.h"
#include "ConcreteProductCircleMovement.generated.h"

/**
 * 
 */
UCLASS()
class L3_HOLOVKO_API AConcreteProductCircleMovement : public AProduct
{
	GENERATED_BODY()

protected:
	virtual void DrawMovementLines(double LinesLifeTime) override;
	virtual void ResetStartSettings() override;
	virtual void Move(float DeltaTime, const double& TimeSinceCreation) override;
	UPROPERTY(EditAnywhere, Category = "Movement")
		double Radius = 100;
	UPROPERTY(EditAnywhere, Category = "Movement")
		double RotationPeriod = 5;
private:
	void CalculateRadialMovement(const double& TimeSinceCreation);
	bool IsHeightAlignedToEndPoint() const;
	double StartMovingDirectionZ = 0;
public:
	UFUNCTION(BlueprintCallable)
		void SetStartSettings(FVector StartPoint, FVector EndPoint, double MovSpeed = 100, bool bShouldBeDestroyed = true, double RotationRadius = 100, double CircleRotationPeriod = 5);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Product.h"
#include "ConcreteProductStraightMovement.generated.h"

/**
 * 
 */
UCLASS()
class L3_HOLOVKO_API AConcreteProductStraightMovement : public AProduct
{
	GENERATED_BODY()
	
protected:
	virtual void DrawMovementLines(double LinesLifeTime) override;
	virtual void ResetStartSettings() override;
	virtual void Move(float DeltaTime, const double& TimeSinceCreation) override;
public:
	UFUNCTION(BlueprintCallable)
		void SetStartSettings(FVector StartPoint, FVector EndPoint, double MovSpeed = 100, bool bShouldBeDestroyed = true);
};

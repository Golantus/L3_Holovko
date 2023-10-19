// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Product.h"
#include "ConcreteProductSinusMovement.generated.h"

/**
 * 
 */
UCLASS()
class L3_HOLOVKO_API AConcreteProductSinusMovement : public AProduct
{
	GENERATED_BODY()
protected:
	virtual void ResetStartSettings() override;
	virtual void Move(float DeltaTime, const double& TimeSinceCreation) override;

	UPROPERTY(EditAnywhere, Category = "Movement")
		FVector Frequency = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, Category = "Movement")
		FVector MaxWobbleDistance = FVector::ZeroVector;

private:
	double MaxDistanceToMove = 0;
	FVector NonWobblingLocation = FVector::ZeroVector;
	void Wobble(const double& TimeSinceCreation);
	double CalculateWobbleLocation(const double& Freq, const double& NonWobbleLocation, const double& MaxWobbleDist, const double& TimeSinceCreation) const;
public:
	UFUNCTION(BlueprintCallable)
		void SetStartSettings(
			FVector StartPoint, FVector EndPoint, double MovSpeed = 100, bool bShouldBeDestroyed = true, 
			FVector Freq = FVector::ZeroVector, FVector MaxWobbleDist = FVector::ZeroVector);
};

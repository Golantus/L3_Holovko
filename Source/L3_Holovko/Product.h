// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/LineBatchComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Product.generated.h"

UCLASS(Abstract)
class L3_HOLOVKO_API AProduct : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AProduct();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void DrawMovementLines(double LinesLifeTime);
	virtual void ResetStartSettings() PURE_VIRTUAL(AProduct::ResetStartSettings);
	virtual void Move(float DeltaTime, const double& TimeSinceCreation) PURE_VIRTUAL(AProduct::Move);

	ULineBatchComponent* LineBatch;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere, Category = "Movement")
		FVector EndMovementPoint = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, Category = "Movement")
		FVector StartMovementPoint = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, Category = "Movement")
		double MovementSpeed = 100.0;
	UPROPERTY(EditAnywhere, Category = "Movement")
		bool bShouldBeDestroyedAtTheEnd = true;
	UPROPERTY(EditAnywhere, Category = "Movement")
		bool bAllowTick = false;
	FVector MovementDirectionVector = FVector::ZeroVector;
	void CalculateMovementDirection();
	void MoveStraight(float DeltaTime);
private:
	void HandleStop();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;
	
	virtual void SetBaseStartSettings(FVector StartPoint, FVector EndPoint, double MovSpeed = 100, bool bShouldBeDestroyed = true);
};

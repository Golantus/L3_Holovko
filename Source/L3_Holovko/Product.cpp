// Fill out your copyright notice in the Description page of Project Settings.


#include "Product.h"

// Sets default values
AProduct::AProduct()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	LineBatch = CreateDefaultSubobject<ULineBatchComponent>(TEXT("LineBatch"));

	RootComponent = StaticMesh;
}


// Called when the game starts or when spawned
void AProduct::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("TICK = %d"), bAllowTick);
	PrimaryActorTick.SetTickFunctionEnable(bAllowTick);
	if (bAllowTick)
	{
		ResetStartSettings();
		DrawMovementLines(15.0);
	}
}

void AProduct::DrawMovementLines(double LinesLifeTime)
{
	const FVector PreSimulationStartLocation = GetActorLocation();
	SetActorLocation(StartMovementPoint);
	ResetStartSettings();
	constexpr double SimulationDeltaTime = 1.0 / 60.0;
	double SimulationPassedTime = SimulationDeltaTime;
	TArray<FBatchedLine> LinesToDraw;
	while (FVector::Dist(GetActorLocation(), EndMovementPoint) > 10)
	{
		FVector LastPosition = GetActorLocation();
		Move(SimulationDeltaTime, SimulationPassedTime);
		LinesToDraw.Add(FBatchedLine(LastPosition, GetActorLocation(), FColor::Red, LinesLifeTime, 3.f, 10.f));
		SimulationPassedTime += SimulationDeltaTime;

	}

	SetActorLocation(PreSimulationStartLocation);
	ResetStartSettings();
	LineBatch->DrawLines(LinesToDraw);
}

void AProduct::MoveStraight(float DeltaTime)
{
	FVector LocationToAdd = MovementDirectionVector * DeltaTime * MovementSpeed;
	this->AddActorWorldOffset(LocationToAdd);
}

void AProduct::CalculateMovementDirection()
{

	MovementDirectionVector = FVector(EndMovementPoint - GetActorLocation());
	MovementDirectionVector.Normalize();
}

void AProduct::HandleStop()
{
	if (bShouldBeDestroyedAtTheEnd)
	{
		Destroy();
	}
	else
	{
		PrimaryActorTick.SetTickFunctionEnable(false);
	}
}

// Called every frame
void AProduct::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime, GetGameTimeSinceCreation());
	if (FVector::Dist(StaticMesh->GetRelativeLocation(), EndMovementPoint) < 10)
	{
		HandleStop();
	}
}

void AProduct::OnConstruction(const FTransform& Transform)
{
	if (bAllowTick)
	{
		DrawMovementLines(1.5);
	}
}

void AProduct::SetBaseStartSettings(FVector StartPoint, FVector EndPoint, double MovSpeed, bool bShouldBeDestroyed)
{
	StartMovementPoint = StartPoint;
	EndMovementPoint = EndPoint;
	MovementSpeed = MovSpeed;
	bShouldBeDestroyedAtTheEnd = bShouldBeDestroyed;

	PrimaryActorTick.SetTickFunctionEnable(true);
	DrawMovementLines(15.0f);
}


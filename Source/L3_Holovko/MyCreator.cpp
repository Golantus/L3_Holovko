// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCreator.h"


AProduct* UMyCreator::SpawnActor()
{
	FVector Location;
	FRotator Rotation;
	return GetWorld()->SpawnActor<AProduct>(ProductType, Location, Rotation);
}
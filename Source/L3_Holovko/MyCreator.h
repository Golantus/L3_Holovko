// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Creator.h"
#include "MyCreator.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class L3_HOLOVKO_API UMyCreator : public UCreator
{
	GENERATED_BODY()
public:
		virtual AProduct* SpawnActor() override;

};

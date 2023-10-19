// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Product.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Creator.generated.h"


UCLASS(Abstract, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class L3_HOLOVKO_API UCreator : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "SpawnActors")
		TSubclassOf<AProduct> ProductType;
public:
	UFUNCTION(BlueprintCallable)
		virtual AProduct* SpawnActor() PURE_VIRTUAL(UCreator::SpawnActor, return NewObject<AProduct>(););
};

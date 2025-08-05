// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SwordFunctions.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_EGRESS_API USwordFunctions : public UObject
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "Sword Functions")
	static TArray<FVector> GetPointsAlongArc(const FVector& StartPoint, const FVector& EndPoint, float ArcHeight, int32 NumPoints);
	UFUNCTION(BlueprintCallable, Category = "Sword Functions")
	static TArray<FVector> GetPointsAlongStraightArc(const FVector& StartPoint, const FVector& EndPoint, float ArcHeight, int32 NumPoints);
	
};

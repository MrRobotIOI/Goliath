// Fill out your copyright notice in the Description page of Project Settings.


#include "SwordFunctions.h"
#include "Math/UnrealMathUtility.h"

TArray<FVector> USwordFunctions::GetPointsAlongArc(const FVector& StartPoint, const FVector& EndPoint, float ArcHeight, int32 NumPoints)
{
	TArray<FVector> Points;

	// Calculate the midpoint between A and B
	FVector Midpoint = (StartPoint + EndPoint) / 2.0f;

	// Calculate the direction from A to B
	FVector Direction = (EndPoint - StartPoint).GetSafeNormal();

	// Calculate the perpendicular direction (upwards for the arc)
	FVector Perpendicular = FVector::CrossProduct(Direction, FVector::UpVector).GetSafeNormal();

	// Calculate the control point
	FVector ControlPoint = Midpoint + Perpendicular * ArcHeight;

	// Generate points along the arc
	for (int32 i = 0; i <= NumPoints; i++)
	{
		float t = static_cast<float>(i) / static_cast<float>(NumPoints);
		float tSquared = t * t;
		float oneMinusT = 1.0f - t;
		float oneMinusTSquared = oneMinusT * oneMinusT;

		FVector Point = (oneMinusTSquared * StartPoint) + (2.0f * oneMinusT * t * ControlPoint) + (tSquared * EndPoint);
		Points.Add(Point);
	}

	return Points;
}
TArray<FVector> USwordFunctions::GetPointsAlongStraightArc(const FVector& StartPoint, const FVector& EndPoint, float ArcHeight, int32 NumPoints)
{
	TArray<FVector> Points;
    
	// Calculate the midpoint between Start and End points
	FVector Midpoint = (StartPoint + EndPoint) / 2.0f;
    
	// Calculate the straight up direction (using world up vector)
	FVector UpDirection = FVector::UpVector;
    
	// Calculate the control point (straight up from midpoint)
	FVector ControlPoint = Midpoint + (UpDirection * ArcHeight);
    
	// Generate points along the arc using quadratic Bezier curve
	for (int32 i = 0; i <= NumPoints; i++)
	{
		float t = static_cast<float>(i) / static_cast<float>(NumPoints);
		float tSquared = t * t;
		float oneMinusT = 1.0f - t;
		float oneMinusTSquared = oneMinusT * oneMinusT;
        
		FVector Point = (oneMinusTSquared * StartPoint) + (2.0f * oneMinusT * t * ControlPoint) + (tSquared * EndPoint);
		Points.Add(Point);
	}
    
	return Points;
}
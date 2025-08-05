// Fill out your copyright notice in the Description page of Project Settings.


#include "WeakSpot.h"


// Sets default values for this component's properties
UWeakSpot::UWeakSpot()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	CapsuleCollider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollider"));
	CapsuleCollider->SetupAttachment(this);
	// ...
}


// Called when the game starts 
void UWeakSpot::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeakSpot::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


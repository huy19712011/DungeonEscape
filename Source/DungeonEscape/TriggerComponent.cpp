// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	UE_LOG(LogTemp, Display, TEXT("Trigger component is constructing"));
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	// UE_LOG(LogTemp, Display, TEXT("Trigger component is alive"));

	// if (MoverActor != nullptr)
	if (MoverActor)
	{
		Mover = MoverActor->FindComponentByClass<UMover>();

		// if (Mover != nullptr)
		if (Mover)
		{
			UE_LOG(LogTemp, Warning, TEXT("Successfully found the mover component"));
			Mover->ShouldMove = true;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to find mover component"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MoverActor is nullptr!!!"));
	}
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// UE_LOG(LogTemp, Display, TEXT("Trigger component is ticking"));
}

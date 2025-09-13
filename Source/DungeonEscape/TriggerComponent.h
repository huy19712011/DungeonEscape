#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Mover.h"
#include "TriggerComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DUNGEONESCAPE_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTriggerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	void Trigger(bool NewTriggerValue);

	UPROPERTY(EditAnywhere)
	bool IsPressurePlate = false;
	
	UPROPERTY(EditAnywhere)
	AActor* MoverActor;

	UPROPERTY(VisibleAnywhere)
	bool IsTriggered = false;

	UMover* Mover;

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverLappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult &SweepResult);

	UFUNCTION()
	void OnOverlapEnd(
		UPrimitiveComponent* OverLappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
	
};

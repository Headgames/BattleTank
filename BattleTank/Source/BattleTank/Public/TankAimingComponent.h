// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/CoreUObject/Public/UObject/Object.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStaticsTypes.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

	// TODO add SetTrurretReference

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:	

	void MoveBarrel(FVector AimDirection);
	UStaticMeshComponent* Barrel = nullptr;
};

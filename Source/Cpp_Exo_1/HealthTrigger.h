// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthTrigger.generated.h"

UCLASS()
class CPP_EXO_1_API AHealthTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealthTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int amount = 1;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* collider = nullptr;

	UPROPERTY(VisibleAnywhere)
	UPointLightComponent* light = nullptr;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* mesh = nullptr;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DecalsBullet.generated.h"

UCLASS()
class CPP_EXO_1_API ADecalsBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecalsBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void FireInDirection(const FVector& ShootDirection);

	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent* projectileComponent = nullptr;

	UPROPERTY(EditAnywhere)
	USphereComponent* collider;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* mesh;
};

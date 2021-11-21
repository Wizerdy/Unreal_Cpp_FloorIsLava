// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "bumper.generated.h"

UCLASS()
class CPP_EXO_1_API ABumper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABumper();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* mesh;
	UPROPERTY(EditAnywhere)
	float launchForce = 100.0f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};

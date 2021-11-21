// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Include box component sinon erreur C2143
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeathTrigger.generated.h"

UCLASS()
class CPP_EXO_1_API ADeathTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeathTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* collider = nullptr;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* mesh = nullptr;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

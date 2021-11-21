// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Cpp_Exo_1Character.h"
#include "CharacterController.generated.h"

/**
 * 
 */
UCLASS()
class CPP_EXO_1_API ACharacterController : public ACpp_Exo_1Character
{
	GENERATED_BODY()

public:
	ACharacterController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
public:
	UPROPERTY(EditAnywhere)
	AActor* respawnPoint;
	UPROPERTY(EditAnywhere)
	int maxHealth = 10;
	UPROPERTY(VisibleAnywhere)
	int health = 10;
	UPROPERTY(EditAnywhere)
	float respawnTime = 3.f;

	UFUNCTION()
	void AppendHealth(int amount);
	UFUNCTION()
	void Die();
	UFUNCTION()
	void Ragdoll();
	UFUNCTION()
	void Unragdoll();
	UFUNCTION()
	void Respawn();
	
	UFUNCTION()
	void OnFire();
};

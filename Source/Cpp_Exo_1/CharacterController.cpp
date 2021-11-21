// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "DecalsBullet.h"

ACharacterController::ACharacterController() {

}

void ACharacterController::BeginPlay() {
	Super::BeginPlay();
	health = maxHealth;
}

void ACharacterController::AppendHealth(int amount) {
	health += amount;
	if (health <= 0) {
		health = 0;
		Die();
	}
	else if (health > maxHealth) {
		health = maxHealth;
	}
}

void ACharacterController::Die() {
	UE_LOG(LogTemp, Warning, TEXT("DEAD"));
	SetActorTickEnabled(false);
	health = 0;
	Ragdoll();
	FTimerHandle timer = FTimerHandle();
	GetWorldTimerManager().SetTimer(timer, this, &ACharacterController::Respawn, respawnTime, false);
}

void ACharacterController::Respawn() {
	Unragdoll();
	SetActorTickEnabled(true);
	GetCharacterMovement()->Velocity = FVector(0.f, 0.f, 0.f);
	SetActorLocation(respawnPoint->GetActorLocation());
	SetActorRotation(respawnPoint->GetActorRotation());
	health = maxHealth;
}

void ACharacterController::Ragdoll() {
	GetCharacterMovement()->MovementMode = EMovementMode::MOVE_None;
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	USkeletalMeshComponent* mesh = GetMesh();
	mesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
	mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	mesh->SetSimulatePhysics(true);
}

void ACharacterController::Unragdoll() {
	USkeletalMeshComponent* mesh = GetMesh();
	UCapsuleComponent* capsule = GetCapsuleComponent();

	// Collisions
	mesh->SetSimulatePhysics(false);
	mesh->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	mesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	capsule->SetWorldLocation(mesh->GetComponentLocation());
	capsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	// Attach Component
	FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, true);
	mesh->AttachToComponent(capsule, rules);
	mesh->SetRelativeLocation(FVector(0.f, 0.f, -95.f));
	mesh->SetRelativeRotation(FRotator(0.f, 270.f, 0.f));

	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
}

void ACharacterController::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ACharacterController::OnFire);
}

void ACharacterController::OnFire() {
	UE_LOG(LogTemp, Warning, TEXT("FIIIIIIRE !"));
	FVector pos = GetActorLocation();
	FVector forward = GetActorForwardVector();
	GetWorld()->SpawnActor<ADecalsBullet>(pos + forward * 100.f, forward.Rotation());
}
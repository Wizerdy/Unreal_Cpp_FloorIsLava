// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathTrigger.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "CharacterController.h"

// Sets default values
ADeathTrigger::ADeathTrigger() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = mesh;

	collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	collider->SetGenerateOverlapEvents(true);
	collider->SetCollisionProfileName(TEXT("Trigger"));
	collider->SetRelativeLocation(FVector(0, 0, 0));
	collider->OnComponentBeginOverlap.AddDynamic(this, &ADeathTrigger::OnBeginOverlap);
}

// Called when the game starts or when spawned
void ADeathTrigger::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void ADeathTrigger::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void ADeathTrigger::OnBeginOverlap(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult) {
	ACharacterController* character = dynamic_cast<ACharacterController*>(otherActor);
	if (!character) { return; }
	//character->LaunchCharacter(FVector(0, 0, 1) * 1000.f, false, true);
	//character->Die();
	character->AppendHealth(-10);
}
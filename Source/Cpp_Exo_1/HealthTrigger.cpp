// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthTrigger.h"
#include "Components/StaticMeshComponent.h"
#include "CharacterController.h"

// Sets default values
AHealthTrigger::AHealthTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	RootComponent = light;

	collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	collider->SetGenerateOverlapEvents(true);
	collider->SetCollisionProfileName(TEXT("Trigger"));
	collider->SetRelativeLocation(FVector(0, 0, 0));
	collider->OnComponentBeginOverlap.AddDynamic(this, &AHealthTrigger::OnBeginOverlap);

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	if (amount < 0) {
		light->SetLightColor(FLinearColor(1.f, 0.f, 0.f));
	}
	else {
		light->SetLightColor(FLinearColor(0.f, 1.f, 0.f));
	}
}

// Called when the game starts or when spawned
void AHealthTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	if (amount < 0) {
		light->SetLightColor(FLinearColor(1.f, 0.f, 0.f));
	}
	else {
		light->SetLightColor(FLinearColor(0.f, 1.f, 0.f));
	}
}

// Called every frame
void AHealthTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHealthTrigger::OnBeginOverlap(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult) {
	//UE_LOG(LogTemp, Warning, TEXT("ENTER !"));
	ACharacterController* character = dynamic_cast<ACharacterController*>(otherActor);
	if (!character) { return; }
	character->AppendHealth(amount);
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "bumper.h"
#include "Math/Vector.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABumper::ABumper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetNotifyRigidBodyCollision(true);

	mesh->OnComponentHit.AddDynamic(this, &ABumper::OnHit);
	RootComponent = mesh;
}

// Called when the game starts or when spawned
void ABumper::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABumper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABumper::OnHit(UPrimitiveComponent* hitComp, AActor* otherActor, UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& hit) {
	// On hit
	ACharacter* character = dynamic_cast<ACharacter*>(otherActor);
	if (!character) { return; }
	character->LaunchCharacter(FVector(0, 0, 1) * launchForce, false, true);
}


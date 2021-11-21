// Fill out your copyright notice in the Description page of Project Settings.


#include "DecalsBullet.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ADecalsBullet::ADecalsBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshRef(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	mesh->SetStaticMesh(MeshRef.Object);
	RootComponent = mesh;

	if (!RootComponent) {
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
	}
	if (!collider) {
		collider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		collider->InitSphereRadius(15.0f);
		//RootComponent = collider;
	}

	projectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	projectileComponent->SetUpdatedComponent(mesh);
	projectileComponent->InitialSpeed = 3000.0f;
	projectileComponent->MaxSpeed = 3000.0f;
	projectileComponent->bRotationFollowsVelocity = true;
	projectileComponent->bShouldBounce = true;
	projectileComponent->Bounciness = 0.3f;
	projectileComponent->ProjectileGravityScale = 0.0f;
}

// Called when the game starts or when spawned
void ADecalsBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADecalsBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADecalsBullet::FireInDirection(const FVector& ShootDirection) {
	projectileComponent->Velocity = ShootDirection * projectileComponent->InitialSpeed;
}
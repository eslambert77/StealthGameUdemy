// Fill out your copyright notice in the Description page of Project Settings.

#include "BlackHole.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StaticMeshActor.h"


// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	InnerSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Inner Sphere Component"));
	InnerSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	InnerSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	InnerSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	InnerSphere->SetupAttachment(MeshComp);


	OuterSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Outer Sphere Component"));
	OuterSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OuterSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	OuterSphere->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	OuterSphere->SetupAttachment(MeshComp);
}

// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//InnerSphere->GetOverlappingComponents()

}

void ABlackHole::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	AStaticMeshActor* PhysicsObject = Cast<AStaticMeshActor>(OtherActor);
	
	if (PhysicsObject)
	{
		
	}
}


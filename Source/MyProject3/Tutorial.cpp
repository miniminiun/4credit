// Fill out your copyright notice in the Description page of Project Settings.


#include "Tutorial.h"

// Sets default values
ATutorial::ATutorial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATutorial::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &ATutorial::SpawnActor, 3, false);
	
}

// Called every frame
void ATutorial::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (lightSource) {
		lightSource->AddActorLocalRotation(FRotator((DeltaTime * speed), 0, 0));
	}
	if (sun)
	{
		FOutputDeviceNull ar;
		sun->CallFunctionByNameWithArguments(TEXT("UpdateSunDirection"), ar, NULL, true);

	}

}

void ATutorial::SpawnActor() {
	FRotator Rotation = FRotator(0, 0, 0);
	FVector SpawnPoint = FVector(-480, 320,300);
	AActor* ap = GetWorld()->SpawnActor<AActor>(actor, SpawnPoint, Rotation);
	ap->SetActorScale3D(FVector(0.5, 0.5, 0.5));
	
	
}


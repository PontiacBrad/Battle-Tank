// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values
AHealthComponent::AHealthComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHealthComponent::TakeDamage(AActor* DamageActor, float Damage, const UDamageType DamageType, AController* InstigatedBy, AActor* DamageCauser)
{

}

// Called every frame
//void AHealthComponent::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}


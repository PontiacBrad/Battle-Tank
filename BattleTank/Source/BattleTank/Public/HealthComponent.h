// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthComponent.generated.h"

class ABattleTankGameModeBase;

UCLASS()
class BATTLETANK_API AHealthComponent : public AActor
{
	GENERATED_BODY()
	
private:
	UProperty(EditAnywhere)
	float DefaultHealth = 100.0f;
	float Health = 0.0f;
	ABattleTankGameModeBase* GameModeRef;

public:	
	// Sets default values for this actor's properties
	AHealthComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	void TakeDamage(AActor* DamageActor, float Damage, const UDamageType DamageType, AController* InstigatedBy, AActor* DamageCauser);

//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
};

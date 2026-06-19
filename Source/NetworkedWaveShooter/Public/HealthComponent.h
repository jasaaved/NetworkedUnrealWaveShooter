// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDamagedDelegate, float, LifePercent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeathDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NETWORKEDWAVESHOOTER_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

public:
	/** Damaged delegate */
	UPROPERTY(BlueprintAssignable)
	FDamagedDelegate OnDamaged;

	/** Fired on the server when health reaches zero */
	UPROPERTY(BlueprintAssignable)
	FDeathDelegate OnDeath;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Health")
	float MaxHealth = 500.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_CurrentHealth, Category = "Health")
	float CurrentHealth = 0.0f;

protected:
	UFUNCTION()
	void OnRep_CurrentHealth();

	

public:
	bool IsDead() const { return CurrentHealth <= 0.0f; }

	float HandleDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};

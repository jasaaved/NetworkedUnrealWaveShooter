// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	SetIsReplicatedByDefault(true);
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner() && GetOwner()->HasAuthority())
	{
		CurrentHealth = MaxHealth;
	}

	// update the HUD
	OnDamaged.Broadcast(1.0f);
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UHealthComponent, MaxHealth);
	DOREPLIFETIME(UHealthComponent, CurrentHealth);
}

void UHealthComponent::OnRep_CurrentHealth() {
	// update the HUD
	OnDamaged.Broadcast(CurrentHealth / MaxHealth);
}

float UHealthComponent::HandleDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) {
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		return 0.0f;
	}
	if (Damage <= 0.0f || IsDead()) {
		return 0.0f;
	}
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);

	if (CurrentHealth <= 0.0f)
	{
		bIsDead = true; //TODO make true when respawned for player
		OnDeath.Broadcast();
	}
	OnRep_CurrentHealth();
	return CurrentHealth;
}


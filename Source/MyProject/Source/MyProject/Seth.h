// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Seth.generated.h"

UCLASS()
class MYPROJECT_API ASeth : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASeth();

#pragma region Variables
	// Variables - this section is visible to the player
	// Health is used to determine how much damage Seth can take
	UPROPERTY(EditAnywhere, Category = "Health")
		int32 Health;
	// Strength and weapon damage together determine how much each strike does
	UPROPERTY(EditAnywhere, Category = "Strength")
		int32 Strength;
	// Dexterity determines the critical strike chance
	UPROPERTY(EditAnywhere, Category = "Dexterity")
		int32 Dexterity;
	// Defense reduces the damage taken together with armor
	UPROPERTY(EditAnywhere, Category = "Defense")
		int32 Defense;
	// How often you hit or miss
	UPROPERTY(EditAnywhere, Category = "Speed")
		int32 Speed;
	// In this case magic is resistance to magic and negative effects
	UPROPERTY(EditAnywhere, Category = "Magic")
		int32 Magic;
	// These two variables are tied to effects in the game
	// Weapon damage will be updated as player acquires new weapons
	UPROPERTY(EditAnywhere, Category = "Weapon Damage")
		int32 WeaponDamage;
	// Armour bonus as well will change as player acquires new armour
	UPROPERTY(EditAnywhere, Category = "Armour Bonus")
		int32 ArmourBonus;
	// Keeps track of the experience gained by the player
	UPROPERTY(EditAnywhere, Category = "Experience")
		int32 Experience;
	// Players current level
	UPROPERTY(EditAnywhere, Category = "Level")
		int32 Level;

	// These variables will not be visible to the player
	float AttackDamage;
	float CriticalChance;
	float NextLevelExperience;
#pragma endregion

#pragma region Functions
	// Calculates the current damage range that can be dealt
	void CalculateDamage();
	// Calculates the critical strike chance
	void CalculateCriticalChance();
	// Levels up and adjusts the player stats
	void LevelUp();

	// Called when a new warrior is obtained
	UFUNCTION(BlueprintCallable, Category = "Power Up")
		void PowerUp();
	// used to summon a new warrior 
	UFUNCTION(BlueprintCallable, Category = "Summon Warrior")
		void SummonWarrior();
	// Called when the game is loaded, sets default values
	UFUNCTION(BlueprintCallable, Category = "Update")
		void Update();
	// Called whenever the player attacks
	UFUNCTION(BlueprintCallable, Category = "Attack")
		void Attack();

#pragma endregion

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

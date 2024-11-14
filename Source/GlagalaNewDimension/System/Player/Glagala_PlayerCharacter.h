// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Glagala_PlayerCharacter.generated.h"

// Forward declarations
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class GLAGALANEWDIMENSION_API AGlagala_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Ctor
	AGlagala_PlayerCharacter();

private:
	// Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* PlayerCamera;

	// Input
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Moving function
	void Move(const FInputActionValue& Value);

	// Flips the character
	void Flip();
	bool IsFacingRight = true;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetPlayerCamera() const { return PlayerCamera; }


	// Health
	UPROPERTY(BlueprintReadWrite)
	float CurrentHealth;
	UPROPERTY(BlueprintReadWrite)
	float MaxHealth = 100;
	


};

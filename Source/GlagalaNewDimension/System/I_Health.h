// I_Health.h
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "I_Health.generated.h"

UENUM(BlueprintType)
enum class E_DamageType : uint8 {
    Normal = 0,
    Fire = 1
};

UENUM(BlueprintType)
enum class E_DamageFilter : uint8 {
    None = 0,
    Player = 1,
    Enemy = 2,
    Destructable = 3
};

// This is the metadata class (inherits from UInterface)
UINTERFACE(BlueprintType)
class  UI_Health : public UInterface
{
    GENERATED_BODY()
};

// This is the pure virtual interface that other classes will implement
class  II_Health
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void AddDamage(float Amount,E_DamageFilter Filter = E_DamageFilter::None, E_DamageType DamageType = E_DamageType::Normal);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetMaxHealth();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    float GetCurrentHealth();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void Kill(E_DamageFilter Filter = E_DamageFilter::None);
};
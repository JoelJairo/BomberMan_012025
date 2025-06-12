// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IBloqueComponent.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UIBloqueComponent : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interfaz para el patrón Composite de bloques.
 */
class BOMBERMAN_012025_API IIBloqueComponent
{
	GENERATED_BODY()

public:
	/** Método para destruir el bloque o grupo de bloques (Composite) */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Composite")
	void Destruir();

	// Método puro virtual según estándar UE4
	// No debe tener implementación, solo PURE_VIRTUAL
	virtual void Destruir_Implementation() PURE_VIRTUAL(IIBloqueComponent::Destruir_Implementation, );
};

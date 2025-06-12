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
 * Interfaz para el patr�n Composite de bloques.
 */
class BOMBERMAN_012025_API IIBloqueComponent
{
	GENERATED_BODY()

public:
	/** M�todo para destruir el bloque o grupo de bloques (Composite) */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Composite")
	void Destruir();

	// M�todo puro virtual seg�n est�ndar UE4
	// No debe tener implementaci�n, solo PURE_VIRTUAL
	virtual void Destruir_Implementation() PURE_VIRTUAL(IIBloqueComponent::Destruir_Implementation, );
};

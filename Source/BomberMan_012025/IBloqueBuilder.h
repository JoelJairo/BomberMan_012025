#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IBloqueBuilder.generated.h"

UINTERFACE(MinimalAPI)
class UIBloqueBuilder : public UInterface
{
    GENERATED_BODY()
};

/**
 * Interfaz del patrón Builder para construir bloques del laberinto
 */
class BOMBERMAN_012025_API IIBloqueBuilder
{
    GENERATED_BODY()

public:
    /** Método para crear un bloque en una posición específica del mundo */
    virtual void ConstruirBloque(UWorld* Mundo, FVector Posicion, int32 ID) = 0;
};
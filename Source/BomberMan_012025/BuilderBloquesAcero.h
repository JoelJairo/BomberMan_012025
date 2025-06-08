#pragma once

#include "CoreMinimal.h"
#include "IBloqueBuilder.h"
#include "BuilderBloquesAcero.generated.h"

/**
 * Builder que construye bloques de tipo Acero
 */
UCLASS()
class BOMBERMAN_012025_API UBuilderBloquesAcero : public UObject, public IIBloqueBuilder
{
    GENERATED_BODY()

public:
    /** Constructor */
    UBuilderBloquesAcero();

    /** Implementación del método de construcción */
    virtual void ConstruirBloque(UWorld* Mundo, FVector Posicion, int32 ID) override;
};
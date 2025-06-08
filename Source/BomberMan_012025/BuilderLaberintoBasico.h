#pragma once

#include "CoreMinimal.h"
#include "IBloqueBuilder.h"
#include "TipoBloque.h"
#include "BuilderLaberintoBasico.generated.h"

class ABloque;

UCLASS()
class BOMBERMAN_012025_API UBuilderLaberintoBasico : public UObject, public IIBloqueBuilder
{
    GENERATED_BODY()

public:
    /** Tipo de bloque a construir (Acero, Ladrillo, etc.) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuración")
    ETipoBloque TipoBloque;

    /** Constructor */
    UBuilderLaberintoBasico();

    /** Implementación del método de construcción */
    virtual void ConstruirBloque(UWorld* Mundo, FVector Posicion, int32 ID) override;
};

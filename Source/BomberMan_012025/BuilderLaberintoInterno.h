#pragma once

#include "CoreMinimal.h"
#include "IBuilderLaberinto.h"
#include "TipoBloque.h"
#include "BuilderLaberintoInterno.generated.h"

//UCLASS()
//class BOMBERMAN_012025_API UBuilderLaberintoBasico : public UObject, public IIBloqueBuilder
//{
//    GENERATED_BODY()
//
//public:
//    /** Tipo de bloque a construir (Acero, Ladrillo, etc.) */
//    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuración")
//    ETipoBloque TipoBloque;
//
//    /** Constructor */
//    UBuilderLaberintoBasico();
//
//    /** Implementación del método de construcción */
//    virtual void ConstruirBloque(UWorld* Mundo, FVector Posicion, int32 ID) override;
//};

UCLASS()
class BOMBERMAN_012025_API UBuilderLaberintoInterno : public UObject, public IBuilderLaberinto
{
    GENERATED_BODY()

public:
    UBuilderLaberintoInterno();

    virtual void ConstruirLaberinto(UWorld* Mundo, int32 Filas, int32 Columnas, float Espaciado) override;
};

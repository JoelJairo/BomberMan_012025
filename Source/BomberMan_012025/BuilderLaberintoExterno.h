#pragma once

#include "CoreMinimal.h"
#include "IBuilderLaberinto.h"
#include "BuilderLaberintoExterno.generated.h"

/**
 * Builder que construye bloques de tipo Acero
 */
//UCLASS()
//class BOMBERMAN_012025_API UBuilderBloquesAcero : public UObject, public IIBloqueBuilder
//{
//    GENERATED_BODY()
//
//public:
//    /** Constructor */
//    UBuilderBloquesAcero();
//
//    /** Implementaci�n del m�todo de construcci�n */
//    virtual void ConstruirBloque(UWorld* Mundo, FVector Posicion, int32 ID) override;
//};

/**
 * Builder que construye laberintos externos
 */
UCLASS()
class BOMBERMAN_012025_API UBuilderLaberintoExterno : public UObject, public IBuilderLaberinto
{
    GENERATED_BODY()

public:
    UBuilderLaberintoExterno();
    /** Implementaci�n del m�todo de construcci�n de laberintos */
    virtual void ConstruirLaberinto(UWorld* Mundo, int32 Filas, int32 Columnas, float Espaciado) override;
};
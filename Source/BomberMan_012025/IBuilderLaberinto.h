#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IBuilderLaberinto.generated.h"

//UINTERFACE(MinimalAPI)
//class UIBloqueBuilder : public UInterface
//{
//    GENERATED_BODY()
//};
//
///**
// * Interfaz del patr�n Builder para construir bloques del laberinto
// */
//class BOMBERMAN_012025_API IIBloqueBuilder
//{
//    GENERATED_BODY()
//
//public:
//    /** M�todo para crear un bloque en una posici�n espec�fica del mundo */
//    virtual void ConstruirBloque(UWorld* Mundo, FVector Posicion, int32 ID) = 0;
//};

UINTERFACE(MinimalAPI)
class UBuilderLaberinto : public UInterface
{
    GENERATED_BODY()
};

class IBuilderLaberinto
{
    GENERATED_BODY()
public:
    virtual void ConstruirLaberinto(UWorld* Mundo, int32 Filas, int32 Columnas, float Espaciado) = 0;
};
#include "BuilderLaberintoBasico.h"
#include "BloqueFactory.h"
#include "Engine/World.h"

UBuilderLaberintoBasico::UBuilderLaberintoBasico()
{
    TipoBloque = ETipoBloque::BLOQUE_ACERO;
}

void UBuilderLaberintoBasico::ConstruirBloque(UWorld* Mundo, FVector Posicion, int32 ID)
{
    if (!Mundo) return;

    ABloque* Bloque = UBloqueFactory::CrearBloque(Mundo, TipoBloque, Posicion, ID);
    if (Bloque)
    {
        UE_LOG(LogTemp, Log, TEXT("Bloque creado por Builder en %s"), *Posicion.ToString());
    }
}
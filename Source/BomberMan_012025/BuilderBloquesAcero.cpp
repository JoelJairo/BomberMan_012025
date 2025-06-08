#include "BuilderBloquesAcero.h"
#include "BloqueFactory.h"
#include "Engine/World.h"

UBuilderBloquesAcero::UBuilderBloquesAcero()
{
    // No necesitas inicializar nada porque el tipo está fijo
}

void UBuilderBloquesAcero::ConstruirBloque(UWorld* Mundo, FVector Posicion, int32 ID)
{
    if (!Mundo) return;

    ABloque* Bloque = UBloqueFactory::CrearBloque(Mundo, ETipoBloque::BLOQUE_ACERO, Posicion, ID);
    if (Bloque)
    {
        UE_LOG(LogTemp, Log, TEXT("Bloque de Acero creado por Builder en %s"), *Posicion.ToString());
    }
}
#include "BuilderLaberintoInterno.h"
#include "BloqueFactory.h"
#include "Engine/World.h"

UBuilderLaberintoInterno::UBuilderLaberintoInterno()
{
}

void UBuilderLaberintoInterno::ConstruirLaberinto(UWorld* Mundo, int32 Filas, int32 Columnas, float Espaciado)
{
    if (!Mundo) return;
    int32 ID = 0;

    // El tamaño real del bloque debe coincidir con el usado en el borde
    float TamanoBloque = Espaciado;

    // Calcula el offset igual que el externo
    int32 TotalFilas = Filas + 2;
    int32 TotalColumnas = Columnas + 2;
    float OffsetX = -((TotalFilas - 1) * TamanoBloque) / 2.0f;
    float OffsetY = -((TotalColumnas - 1) * TamanoBloque) / 2.0f;

    // Solo crear bloques en el área interna (sin tocar los bordes)
    for (int32 Fila = 1; Fila < TotalFilas - 1; ++Fila)
    {
        for (int32 Columna = 1; Columna < TotalColumnas - 1; ++Columna)
        {
            FVector Posicion(
                OffsetX + Fila * TamanoBloque,
                OffsetY + Columna * TamanoBloque,
                0.0f
            );
            UBloqueFactory::CrearBloque(Mundo, ETipoBloque::BLOQUE_LADRILLO, Posicion, ID++);
        }
    }
}

#include "DirectorLaberinto.h"
#include "IBloqueBuilder.h"

void UDirectorLaberinto::ConstruirLaberinto(UWorld* Mundo, TScriptInterface<IIBloqueBuilder> Builder, int32 Filas, int32 Columnas, float Espaciado)
{
    if (!Mundo || !Builder) return;

    int32 ID = 0;

    for (int32 Fila = 0; Fila < Filas; ++Fila)
    {
        for (int32 Col = 0; Col < Columnas; ++Col)
        {
            FVector Posicion = FVector(Fila * Espaciado, Col * Espaciado, 0.0f);
            Builder->ConstruirBloque(Mundo, Posicion, ID);
            ID++;
        }
    }
}
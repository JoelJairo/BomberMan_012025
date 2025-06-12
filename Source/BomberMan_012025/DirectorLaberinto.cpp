#include "DirectorLaberinto.h"
#include "IBuilderLaberinto.h"

void UDirectorLaberinto::SetBuilder(TScriptInterface<IBuilderLaberinto> InBuilder)
{
    Builder = InBuilder;
}

void UDirectorLaberinto::ConstruirLaberinto(UWorld* Mundo, int32 Filas, int32 Columnas, float Espaciado)
{
    if (!Mundo || !Builder) return;
    // El builder concreto implementa la lógica de construcción (bordes, interior, etc.)
    Builder->ConstruirLaberinto(Mundo, Filas, Columnas, Espaciado);
}
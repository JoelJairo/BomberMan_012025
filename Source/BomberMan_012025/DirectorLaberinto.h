#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DirectorLaberinto.generated.h"

class IIBloqueBuilder;

/**
 * Director que construye el laberinto usando un Builder
 */
UCLASS()
class BOMBERMAN_012025_API UDirectorLaberinto : public UObject
{
    GENERATED_BODY()

public:
    void ConstruirLaberinto(UWorld* Mundo, TScriptInterface<IIBloqueBuilder> Builder, int32 Filas, int32 Columnas, float Espaciado);
};
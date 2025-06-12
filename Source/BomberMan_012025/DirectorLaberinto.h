#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IBuilderLaberinto.h"
#include <functional>
#include "DirectorLaberinto.generated.h"

class IBuilderLaberinto;

/**
 * Director que construye el laberinto usando un Builder
 */
UCLASS()
class BOMBERMAN_012025_API UDirectorLaberinto : public UObject
{
    GENERATED_BODY()

public:
    void SetBuilder(TScriptInterface<IBuilderLaberinto> InBuilder);

    void ConstruirLaberinto(UWorld* Mundo, int32 Filas, int32 Columnas, float Espaciado);

private:
    TScriptInterface<IBuilderLaberinto> Builder;
};
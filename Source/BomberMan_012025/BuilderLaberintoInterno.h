#pragma once

#include "CoreMinimal.h"
#include "IBuilderLaberinto.h"
#include "GrupoBloques.h"
#include "BuilderLaberintoInterno.generated.h"

UCLASS()
class BOMBERMAN_012025_API UBuilderLaberintoInterno : public UObject, public IBuilderLaberinto
{
    GENERATED_BODY()

public:
    UBuilderLaberintoInterno();

    virtual void ConstruirLaberinto(UWorld* Mundo, int32 Filas, int32 Columnas, float Espaciado) override;

    void DestruirGrupoEspecial();

protected:
    UPROPERTY()
    AGrupoBloques* GrupoEspecial;
};

#include "BuilderLaberintoInterno.h"
#include "BloqueFactory.h"
#include "GrupoBloques.h"
#include "Engine/World.h"

UBuilderLaberintoInterno::UBuilderLaberintoInterno()
{
    GrupoEspecial = nullptr;
}

void UBuilderLaberintoInterno::ConstruirLaberinto(UWorld* Mundo, int32 Filas, int32 Columnas, float Espaciado)
{
    if (!Mundo) return;
    int32 ID = 0;

    float TamanoBloque = Espaciado;
    int32 TotalFilas = Filas + 2;
    int32 TotalColumnas = Columnas + 2;
    float OffsetX = -((TotalFilas - 1) * TamanoBloque) / 2.0f;
    float OffsetY = -((TotalColumnas - 1) * TamanoBloque) / 2.0f;

    // Crear todos los bloques internos
    TArray<ABloque*> BloquesCreados;
    for (int32 Fila = 1; Fila < TotalFilas - 1; ++Fila)
    {
        for (int32 Col = 1; Col < TotalColumnas - 1; ++Col)
        {
            FVector Posicion(
                OffsetX + Fila * TamanoBloque,
                OffsetY + Col * TamanoBloque,
                0.0f
            );
            ABloque* Bloque = UBloqueFactory::CrearBloque(Mundo, ETipoBloque::BLOQUE_LADRILLO, Posicion, ID++);
            if (Bloque)
            {
                BloquesCreados.Add(Bloque);
            }
        }
    }

    // Crear un grupo con solo 2 bloques consecutivos en fila o columna
    if (BloquesCreados.Num() >= 2)
    {
        GrupoEspecial = Mundo->SpawnActor<AGrupoBloques>();
        if (GrupoEspecial)
        {
            // Buscar dos bloques consecutivos en la misma fila
            bool GrupoCreado = false;
            for (int32 i = 0; i < BloquesCreados.Num() - 1; ++i)
            {
                FVector PosA = BloquesCreados[i]->GetActorLocation();
                FVector PosB = BloquesCreados[i + 1]->GetActorLocation();

                // En fila (X igual, Y consecutivo)
                if (FMath::IsNearlyEqual(PosA.X, PosB.X) && FMath::Abs(PosA.Y - PosB.Y) <= TamanoBloque * 1.1f)
                {
                    GrupoEspecial->Agregar(BloquesCreados[i]);
                    GrupoEspecial->Agregar(BloquesCreados[i + 1]);
                    GrupoCreado = true;
                    break;
                }
                // En columna (Y igual, X consecutivo)
                if (FMath::IsNearlyEqual(PosA.Y, PosB.Y) && FMath::Abs(PosA.X - PosB.X) <= TamanoBloque * 1.1f)
                {
                    GrupoEspecial->Agregar(BloquesCreados[i]);
                    GrupoEspecial->Agregar(BloquesCreados[i + 1]);
                    GrupoCreado = true;
                    break;
                }
            }
            // Si no se encontró par consecutivo, agrega los dos primeros
            if (!GrupoCreado && BloquesCreados.Num() >= 2)
            {
                GrupoEspecial->Agregar(BloquesCreados[0]);
                GrupoEspecial->Agregar(BloquesCreados[1]);
            }
        }
    }
}

// Llama a esto desde otro lado para destruir el grupo especial
void UBuilderLaberintoInterno::DestruirGrupoEspecial()
{
    if (GrupoEspecial)
    {
        IIBloqueComponent::Execute_Destruir(GrupoEspecial);
    }
}




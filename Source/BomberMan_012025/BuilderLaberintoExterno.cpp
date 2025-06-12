#include "BuilderLaberintoExterno.h"
#include "BloqueFactory.h"
#include "Engine/World.h"
#include "BloqueAcero.h"

UBuilderLaberintoExterno::UBuilderLaberintoExterno()
{
    // No necesitas inicializar nada porque el tipo está fijo
}

void UBuilderLaberintoExterno::ConstruirLaberinto(UWorld* Mundo, int32 Filas, int32 Columnas, float Espaciado)
{
    if (!Mundo || Filas <= 0 || Columnas <= 0 || Espaciado <= 0.0f)
    {
        UE_LOG(LogTemp, Warning, TEXT("Parámetros inválidos para construir el laberinto externo."));
        return;
    }
    int32 ID = 0;

    // Obtener el tamaño real del bloque de acero
    float TamanoBloque = Espaciado;
    ABloqueAcero* BloqueTemp = Cast<ABloqueAcero>(UBloqueFactory::CrearBloque(Mundo, ETipoBloque::BLOQUE_ACERO, FVector::ZeroVector, -1));
    if (BloqueTemp && BloqueTemp->GetRootComponent())
    {
        FVector Extent = BloqueTemp->GetRootComponent()->Bounds.BoxExtent * 2.0f;
        TamanoBloque = FMath::Max(Extent.X, Extent.Y);
        BloqueTemp->Destroy();
    }

    // El borde debe rodear el área de los bloques internos, así que el offset debe centrar el laberinto
    int32 TotalFilas = Filas + 15;
    int32 TotalColumnas = Columnas + 15;

    // Calcula el offset para centrar el laberinto
    float OffsetX = -((TotalFilas - 1) * TamanoBloque) / 2.0f;
    float OffsetY = -((TotalColumnas - 1) * TamanoBloque) / 2.0f;

    for (int32 Fila = 0; Fila < TotalFilas; ++Fila)
    {
        for (int32 Columna = 0; Columna < TotalColumnas; ++Columna)
        {
            if (Fila == 0 || Fila == TotalFilas - 1 || Columna == 0 || Columna == TotalColumnas - 1)
            {
                FVector Posicion(
                    OffsetX + Fila * TamanoBloque,
                    OffsetY + Columna * TamanoBloque,
                    0.0f
                );
                ABloque* Bloque = UBloqueFactory::CrearBloque(Mundo, ETipoBloque::BLOQUE_ACERO, Posicion, ID++);
                if (Bloque)
                {
                    Bloque->SetActorLabel(FString::Printf(TEXT("BloqueAcero_%d_%d"), Fila, Columna));
                }
            }
        }
    }
}

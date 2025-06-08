#include "GeneradorBloques.h"
#include "BloqueFactory.h"
#include "Bloque.h"

AGeneradorBloques::AGeneradorBloques()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AGeneradorBloques::BeginPlay()
{
    Super::BeginPlay();
    GenerarMapa();
}

void AGeneradorBloques::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AGeneradorBloques::GenerarMapa()
{
    UWorld* Mundo = GetWorld();
    if (!Mundo) return;

    for (int32 fila = 0; fila < Filas; ++fila)
    {
        for (int32 col = 0; col < Columnas; ++col)
        {
            FVector Posicion = FVector(fila * Separacion, col * Separacion, 0.0f);

            // Alternar tipos para ejemplo, puedes usar lógica personalizada
            ETipoBloque Tipo = static_cast<ETipoBloque>((fila + col) % static_cast<int32>(ETipoBloque::MAX));

            ABloque* NuevoBloque = UBloqueFactory::CrearBloque(Mundo, Tipo, Posicion, IDContador);
            if (NuevoBloque)
            {
                MapaDeBloques.Add(IDContador, NuevoBloque);
                IDContador++;
            }
        }
    }
}
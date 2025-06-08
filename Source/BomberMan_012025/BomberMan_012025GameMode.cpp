// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "BuilderLaberintoBasico.h"
#include "DirectorLaberinto.h"
#include "BuilderBloquesAcero.h"

ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{
	// set default pawn class to Blueprint'/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter.ThirdPersonCharacter'
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	else
		{
		UE_LOG(LogTemp, Warning, TEXT("PlayerPawnBPClass not found! Please check the path."));
	}

}

void ABomberMan_012025GameMode::BeginPlay()
{
	Super::BeginPlay();

    UWorld* Mundo = GetWorld();
    if (!Mundo) return;

    UBuilderLaberintoBasico* BuilderLadrillo = NewObject<UBuilderLaberintoBasico>();
    BuilderLadrillo->TipoBloque = ETipoBloque::BLOQUE_LADRILLO;

    UBuilderBloquesAcero* BuilderAcero = NewObject<UBuilderBloquesAcero>();

    UDirectorLaberinto* Director = NewObject<UDirectorLaberinto>();

    int32 Filas = 10;
    int32 Columnas = 10;
    float Espaciado = 200.0f;
    int32 ID = 0;

    // Mover el laberinto hacia la esquina inferior izquierda (respecto al origen del mundo)
    FVector OffsetInicial = FVector(
        -((Filas - 1) * Espaciado) / 2.0f,
        -((Columnas - 1) * Espaciado) / 2.0f,
        0.0f // Z se mantiene igual
    );

    for (int32 Fila = 0; Fila < Filas; ++Fila)
    {
        for (int32 Col = 0; Col < Columnas; ++Col)
        {
            FVector Pos = OffsetInicial + FVector(Fila * Espaciado, Col * Espaciado, 0.0f);

            bool EsBorde = Fila == 0 || Col == 0 || Fila == Filas - 1 || Col == Columnas - 1;

            if (EsBorde)
            {
                BuilderAcero->ConstruirBloque(Mundo, Pos, ID++);
            }
            else
            {
                BuilderLadrillo->ConstruirBloque(Mundo, Pos, ID++);
            }
        }
    }
}

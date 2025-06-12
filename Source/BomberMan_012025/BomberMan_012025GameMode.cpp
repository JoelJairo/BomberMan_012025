// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "BuilderLaberintoExterno.h"
#include "BuilderLaberintoInterno.h"
#include "DirectorLaberinto.h"

ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{
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

    int32 Filas = 10;
    int32 Columnas = 10;
    float Espaciado = 200.0f;

    UDirectorLaberinto* Director = NewObject<UDirectorLaberinto>();

    // Construir bordes del laberinto
    UBuilderLaberintoExterno* BuilderExterno = NewObject<UBuilderLaberintoExterno>();
    Director->SetBuilder(BuilderExterno);
    Director->ConstruirLaberinto(Mundo, Filas, Columnas, Espaciado);

    // Construir interior del laberinto
    UBuilderLaberintoInterno* BuilderInterno = NewObject<UBuilderLaberintoInterno>();
    Director->SetBuilder(BuilderInterno);
    Director->ConstruirLaberinto(Mundo, Filas, Columnas, Espaciado);
}

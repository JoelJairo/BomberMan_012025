// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "BuilderLaberintoExterno.h"
#include "BuilderLaberintoInterno.h"
#include "DirectorLaberinto.h"
#include "BloqueFactory.h"
#include "BloqueLadrillo.h"
#include "BloqueAcero.h"
#include "TipoBloque.h"
#include "Engine/World.h"

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

	// Spawn prototype blocks only if not already present
	ABloqueLadrillo* PrototipoLadrillo = Mundo->SpawnActor<ABloqueLadrillo>();
	if (PrototipoLadrillo)
	{
		UBloqueFactory::RegistrarPrototipo(ETipoBloque::BLOQUE_LADRILLO, PrototipoLadrillo);
	}

	ABloqueAcero* PrototipoAcero = Mundo->SpawnActor<ABloqueAcero>();
	if (PrototipoAcero)
	{
		UBloqueFactory::RegistrarPrototipo(ETipoBloque::BLOQUE_ACERO, PrototipoAcero);
	}

	int32 Filas = 10;
	int32 Columnas = 10;
	float Espaciado = 200.0f;

	UDirectorLaberinto* Director = NewObject<UDirectorLaberinto>(this);
	if (!Director) return;

	// Construir bordes del laberinto
	UBuilderLaberintoExterno* BuilderExterno = NewObject<UBuilderLaberintoExterno>(this);
	if (BuilderExterno)
	{
		Director->SetBuilder(BuilderExterno);
		Director->ConstruirLaberinto(Mundo, Filas, Columnas, Espaciado);
	}

	// Construir interior del laberinto
	UBuilderLaberintoInterno* BuilderInterno = NewObject<UBuilderLaberintoInterno>(this);
	if (BuilderInterno)
	{
		Director->SetBuilder(BuilderInterno);
		Director->ConstruirLaberinto(Mundo, Filas, Columnas, Espaciado);
	}
}

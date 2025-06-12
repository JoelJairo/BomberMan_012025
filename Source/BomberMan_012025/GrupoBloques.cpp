// Fill out your copyright notice in the Description page of Project Settings.

#include "GrupoBloques.h"

/**
 * Sets default values
*/
AGrupoBloques::AGrupoBloques()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
}

/**
 * Called when the game starts or when spawned
*/
void AGrupoBloques::BeginPlay()
{
    Super::BeginPlay();
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void AGrupoBloques::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AGrupoBloques::Agregar(UObject* Bloque)
{
    if (Bloque && Bloque->GetClass()->ImplementsInterface(UIBloqueComponent::StaticClass()))
    {
        Hijos.Add(TScriptInterface<IIBloqueComponent>(Bloque));
    }
}

void AGrupoBloques::Remover(UObject* Bloque)
{
    Hijos.Remove(TScriptInterface<IIBloqueComponent>(Bloque));
}

void AGrupoBloques::Destruir_Implementation()
{
    for (auto& Hijo : Hijos)
    {
        if (Hijo)
        {
            Hijo->Execute_Destruir(Hijo.GetObject());
        }
    }
    Destroy();
}


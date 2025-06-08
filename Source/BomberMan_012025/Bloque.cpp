#include "Bloque.h"

ABloque::ABloque()
{
	PrimaryActorTick.bCanEverTick = false;
	Malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
	RootComponent = Malla;
	// asignar una malla por defecto
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaBloque(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MallaBloque.Succeeded())
	{
		Malla->SetStaticMesh(MallaBloque.Object);
	}
}



void ABloque::ComportamientoIndividual()
{
	// Ejemplo genérico
	UE_LOG(LogTemp, Warning, TEXT("Comportamiento individual del bloque base."));
}

void ABloque::ComportamientoGrupo()
{
	// Ejemplo genérico
	UE_LOG(LogTemp, Warning, TEXT("Comportamiento grupal del bloque base."));
}
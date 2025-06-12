#include "Bloque.h"
#include "Engine/World.h"

ABloque::ABloque()
{
	PrimaryActorTick.bCanEverTick = false;
	Malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
	RootComponent = Malla;
	TipoBloque = ETipoBloque::Ninguno;

	// Example: Assign a default mesh in ABloque.cpp constructor
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (MeshAsset.Succeeded())
	{
		Malla->SetStaticMesh(MeshAsset.Object);
	}

}

ABloque* ABloque::Clonar(UWorld* Mundo, const FVector& Posicion, int32 ID)
{
	if (!Mundo) return nullptr;
	FActorSpawnParameters SpawnParams;
	SpawnParams.Name = FName(*FString::Printf(TEXT("Bloque_%d"), ID));
	ABloque* NuevoBloque = Mundo->SpawnActor<ABloque>(GetClass(), Posicion, FRotator::ZeroRotator, SpawnParams);
	if (NuevoBloque)
	{
		NuevoBloque->TipoBloque = this->TipoBloque;
	}
	return NuevoBloque;
}

void ABloque::ComportamientoIndividual()
{
	// Implementar comportamiento individual
}

void ABloque::ComportamientoGrupo()
{
	// Implementar comportamiento grupal
}

void ABloque::Destruir_Implementation()
{
	Destroy();
}
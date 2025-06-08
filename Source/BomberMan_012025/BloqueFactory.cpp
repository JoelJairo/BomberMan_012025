#include "BloqueFactory.h"
#include "BloqueAcero.h"
#include "BloqueLadrillo.h"
// Incluye las dem�s clases espec�ficas

ABloque* UBloqueFactory::CrearBloque(UWorld* Mundo, ETipoBloque Tipo, const FVector& Posicion, int32 ID)
{
	if (!Mundo) return nullptr;

	ABloque* NuevoBloque = nullptr;

	switch (Tipo)
	{
	case ETipoBloque::BLOQUE_ACERO:
		NuevoBloque = Mundo->SpawnActor<ABloqueAcero>(Posicion, FRotator::ZeroRotator);
		break;
	case ETipoBloque::BLOQUE_MADERA:
		NuevoBloque = Mundo->SpawnActor<ABloqueLadrillo>(Posicion, FRotator::ZeroRotator);
		break;
		// Agrega otros tipos...
	default:
		break;
	}

	if (NuevoBloque)
	{
		// Aqu� podr�as cargar din�micamente mallas/materiales desde Content
		// y aplicar InicializarBloque(Malla, Material);
	}

	return NuevoBloque;
}
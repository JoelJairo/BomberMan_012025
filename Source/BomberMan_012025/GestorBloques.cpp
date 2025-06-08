#include "GestorBloques.h"
#include "BloqueFactory.h"

void AGestorBloques::CrearYRegistrarBloque(UWorld* Mundo, ETipoBloque Tipo, const FVector& Posicion, int32 ID)
{
	if (MapaBloques.Contains(ID))
	{
		UE_LOG(LogTemp, Warning, TEXT("ID de bloque duplicado: %d"), ID);
		return;
	}

	ABloque* NuevoBloque = UBloqueFactory::CrearBloque(Mundo, Tipo, Posicion, ID);
	if (NuevoBloque)
	{
		MapaBloques.Add(ID, NuevoBloque);
	}
}
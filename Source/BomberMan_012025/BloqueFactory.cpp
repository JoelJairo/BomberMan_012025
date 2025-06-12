#include "BloqueFactory.h"
#include "BloqueAcero.h"
#include "BloqueLadrillo.h"
// Incluye las demás clases específicas

TMap<ETipoBloque, ABloque*> UBloqueFactory::Prototipos;

void UBloqueFactory::RegistrarPrototipo(ETipoBloque Tipo, ABloque* Prototipo)
{
    Prototipos.Add(Tipo, Prototipo);
}

ABloque* UBloqueFactory::CrearBloque(UWorld* Mundo, ETipoBloque Tipo, const FVector& Posicion, int32 ID)
{
    if (Prototipos.Contains(Tipo))
    {
        return Prototipos[Tipo]->Clonar(Mundo, Posicion, ID);
    }
    // Fallback: crear desde cero si no hay prototipo
    return nullptr;
}
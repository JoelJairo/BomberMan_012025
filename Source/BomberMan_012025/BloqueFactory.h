#pragma once

#include "CoreMinimal.h"
#include "TipoBloque.h"
#include "Bloque.h"
#include "BloqueFactory.generated.h"

/**
 * F�brica para crear bloques seg�n su tipo.
 */
UCLASS()
class BOMBERMAN_012025_API UBloqueFactory : public UObject
{
	GENERATED_BODY()

private:
	static TMap<ETipoBloque, ABloque*> Prototipos;

public:
	/**
	 * Registra un prototipo de bloque para un tipo espec�fico.
	 * @param Tipo Tipo de bloque.
	 * @param Prototipo Instancia del bloque que servir� como prototipo.
	 */
	static void RegistrarPrototipo(ETipoBloque Tipo, ABloque* Prototipo);

	/**
	 * Crea una instancia de bloque basado en el tipo especificado.
	 * @param Mundo El mundo actual.
	 * @param Tipo Tipo de bloque a crear.
	 * @param Posici�n Posici�n donde se colocar� el bloque.
	 * @param ID Identificador �nico del bloque.
	 * @return Referencia al bloque creado.
	 */
	UFUNCTION(BlueprintCallable, Category = "Factory")
	static ABloque* CrearBloque(UWorld* Mundo, ETipoBloque Tipo, const FVector& Posicion, int32 ID);
};
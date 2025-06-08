#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "GestorBloques.generated.h"

/**
 * Clase que gestiona todos los bloques del juego.
 */
UCLASS()
class BOMBERMAN_012025_API AGestorBloques : public AActor
{
	GENERATED_BODY()

public:
	/** Mapa de bloques con IDs únicos */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bloques")
	TMap<int32, ABloque*> MapaBloques;

	/** Crea y registra un nuevo bloque */
	UFUNCTION(BlueprintCallable, Category = "Bloques")
	void CrearYRegistrarBloque(UWorld* Mundo, ETipoBloque Tipo, const FVector& Posicion, int32 ID);
};
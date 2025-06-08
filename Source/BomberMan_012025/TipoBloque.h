#pragma once

#include "CoreMinimal.h"
#include "TipoBloque.generated.h"

/**
 * Enumeración de tipos de bloque.
 */
UENUM(BlueprintType)
enum class ETipoBloque : uint8
{
	BLOQUE_ACERO     UMETA(DisplayName = "Acero"),
	BLOQUE_MADERA    UMETA(DisplayName = "Madera"),
	BLOQUE_LADRILLO  UMETA(DisplayName = "Ladrillo"),
	BLOQUE_CONCRETO  UMETA(DisplayName = "Concreto"),
	BLOQUE_DINAMICO  UMETA(DisplayName = "Dinamico"),
	MAX        UMETA(Hidden)  // Este no es un tipo real, solo sirve para contar

};
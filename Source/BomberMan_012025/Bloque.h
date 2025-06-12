#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TipoBloque.h"
#include "IBloqueComponent.h"
#include "Bloque.generated.h"

/**
 * Clase base para los bloques del juego Bomberman.
 */
UCLASS()
class BOMBERMAN_012025_API ABloque : public AActor, public IIBloqueComponent
{
	GENERATED_BODY()

public:
	/** Constructor */
	ABloque();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bloque")
	UStaticMeshComponent* Malla;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bloque")
	ETipoBloque TipoBloque;


public:

	/** 
	* Ejecuta el comportamiento individual del bloque. 
	*/
	UFUNCTION(BlueprintCallable, Category="Bloque")
	virtual void ComportamientoIndividual();

	/** Comportamiento en grupo del bloque */
	UFUNCTION(BlueprintCallable, Category = "Bloque")
	virtual void ComportamientoGrupo();

	/** Clona el bloque en una posici�n espec�fica */
	virtual ABloque* Clonar(UWorld* Mundo, const FVector& Posicion, int32 ID);

	/** Implementaci�n de la destrucci�n del bloque */
	virtual void Destruir_Implementation() override;
};
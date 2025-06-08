#pragma once

#include "Bloque.h"
#include "BloqueAcero.generated.h"

/**
 * Bloque de tipo Acero.
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueAcero : public ABloque
{
	GENERATED_BODY()
protected:
	/**
	* Sonido que se reproduce cuando el bloque de acero recibe un impacto.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* SonidoImpactoMetalico;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Estado")
	bool bEsIndestructible = false;

	UMaterialInstanceDynamic* DynamicMaterialInst;


	/** Material original del bloque */
	UPROPERTY()
	UMaterialInterface* MaterialOriginal;

	/** Material brillante para el estado de grupo */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grupo")
	UMaterialInterface* MaterialGrupo;

	/** Duración del estado grupal en segundos */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grupo")
	float DuracionEstadoGrupo;

	/** Handle para manejar el temporizador del estado grupal */
	FTimerHandle TimerHandleRestaurarEstado;

	

public:
	ABloqueAcero();

	virtual void BeginPlay() override;

	/** @brief Comportamiento individual del bloque de acero */
	virtual void ComportamientoIndividual() override;

	/**
	* Comportamiento grupal del bloque de acero.
	* Se activa cuando está junto a otros bloques de acero.
	*/
	virtual void ComportamientoGrupo() override;

	/** Termina el estado grupal y vuelve a la normalidad */
	void RestaurarEstadoNormal();
};
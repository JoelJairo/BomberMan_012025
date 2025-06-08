#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueLadrillo.generated.h"

/**
 * Bloque de Ladrillo: Frágil, puede destruirse con facilidad y en grupo colapsa en cadena.
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueLadrillo : public ABloque
{
    GENERATED_BODY()

public:
    ABloqueLadrillo();

    /** Comportamiento al recibir impacto directo */
    virtual void ComportamientoIndividual() override;

    /** Comportamiento al formar grupo */
    virtual void ComportamientoGrupo() override;

protected:
    /** Material original del ladrillo */
    UPROPERTY()
    UMaterialInterface* MaterialOriginal;

    /** Material de daño para representar deterioro */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grupo")
    UMaterialInterface* MaterialDaniado;

    /** Sonido al romperse */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sonido")
    USoundBase* SonidoRompimiento;

    /** Tiempo de destrucción después del colapso grupal */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grupo")
    float TiempoDestruccion;

    /** Timer interno para destrucción */
    FTimerHandle TimerHandleDestruir;

    /** Elimina el actor de la escena */
    void DestruirBloque();

    /** Begin play */
	virtual void BeginPlay() override;
};
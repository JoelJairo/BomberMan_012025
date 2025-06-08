#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GeneradorBloques.generated.h"

UCLASS()
class BOMBERMAN_012025_API AGeneradorBloques : public AActor
{
    GENERATED_BODY()

public:
    AGeneradorBloques();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    void GenerarMapa();

    UPROPERTY(EditAnywhere, Category = "Configuración")
    int32 Filas = 10;

    UPROPERTY(EditAnywhere, Category = "Configuración")
    int32 Columnas = 10;

    UPROPERTY(EditAnywhere, Category = "Configuración")
    float Separacion = 200.0f;

    UPROPERTY()
    TMap<int32, class ABloque*> MapaDeBloques;

    int32 IDContador = 0;
};
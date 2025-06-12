// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBloqueComponent.h"
#include "GrupoBloques.generated.h"

/**
 *
*/
UCLASS()
class BOMBERMAN_012025_API AGrupoBloques : public AActor, public IIBloqueComponent
{
	GENERATED_BODY()
	
public:	
	/**
	 * Sets default values for this actor's properties
	*/
	AGrupoBloques();

	UFUNCTION(BlueprintCallable, Category = "Composite")
	void Agregar(UObject* Bloque);

	UFUNCTION(BlueprintCallable, Category = "Composite")
	void Remover(UObject* Bloque);

	virtual void Destruir_Implementation() override;

protected:
	/**
	 * Called when the game starts or when spawned
	*/
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<TScriptInterface<IIBloqueComponent>> Hijos;

public:	
	/**
	 * Called every frame
	 * @param DeltaTime Game time elapsed during last frame modified by the time dilation 
	*/
	virtual void Tick(float DeltaTime) override;

};
